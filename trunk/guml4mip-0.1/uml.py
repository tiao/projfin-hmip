##############################################################################
# guml4mip: GUI UML Management for Mobile IP
#
# An abstract interface for UML instances.
#
# Copyright (C) 2009 Cleiber Marques da Silva
# Copyright (C) 2005 Matthew Palmer
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation (version 2 of the License)
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
##############################################################################               

import re
from ConfigParser import SafeConfigParser, NoSectionError
import time
import os
import gtk
import gobject
import vte
import sys
import string
import guml_debug
import md5

def list(directory):
	"""Return the controller objects for all of the UMLs available in a
	   dictionary, where the key is the umid and the value is the
	   controller object for the UML."""

	namematch = re.compile('^([a-zA-Z0-9_-]+)\.conf$')

	if os.path.isdir(directory) == False:
		print "erro %s" % directory
		return False

	conflist = {}
	for entry in os.listdir(directory):
		matches = namematch.match(entry)
		if matches:
			umid = matches.group(1)
			conflist[umid] = controller(umid, directory)
	
	create_conf_file(conflist)
	return conflist

def conf_route(networks):
	zebra = "! guml4mip zebra configuration file\\nhostname Router\\npassword zebra\\nenable password zebra\\ninterface log"
	ripngd = "! guml4mip RIPngd configuration file\\nhostname ripngd\\npassword zebra\\nrouter ripng"

	for dev in networks:
		zebra = zebra + "\\ninterface %s" % dev
		ripngd = ripngd + "\\nnetwork %s" % dev

	str = "\techo -e \"%s\" > /etc/quagga/zebra.conf\n\
\techo -e \"%s\" > /etc/quagga/ripngd.conf\n\
\t/usr/lib/quagga/zebra -d -f /etc/quagga/zebra.conf &\n\
\t/usr/lib/quagga/ripngd -d -f /etc/quagga/ripngd.conf &\n" % (zebra, ripngd)
	return str

def conf_network(networks, type):
	str = "\
\tip -6 route flush all\n\
\tip link set dev lo up\n"

	for dev in networks:
		str = str + "\
\tip link set dev %s down\n\
\tip link set dev %s up\n\
\tip -6 addr add %s dev %s\n" % (dev, dev, networks[dev]['ip'], dev)

	if type == "router":
		str = str + "\
\t/sbin/sysctl -w net.ipv6.conf.all.forwarding=1\n\
\t/sbin/sysctl -w net.ipv6.conf.all.proxy_ndp=1\n\
\t/sbin/sysctl -w net.ipv6.conf.all.autoconf=0\n\
\t/sbin/sysctl -w net.ipv6.conf.all.accept_ra=0\n\
\t/sbin/sysctl -w net.ipv6.conf.all.accept_redirects=0\n" + conf_route(networks)

	elif type == "node":
		str = str + "\
\t/sbin/sysctl -w net.ipv6.conf.all.forwarding=0\n\
\t/sbin/sysctl -w net.ipv6.conf.all.autoconf=1\n\
\t/sbin/sysctl -w net.ipv6.conf.all.accept_ra=1\n\
\t/sbin/sysctl -w net.ipv6.conf.all.accept_redirects=1\n"

	return str

def conf_daemons(daemons):
	str = ""
	for name in daemons:
		str = str + "\
\tsleep 1\n\
\t%s\n" % daemons[name]
	return str

def create_conf_file(conflist):
	str = "\
#!/bin/sh\n\
#\n\
# guml4mip.conf: script for configure UML images\n\
NODO=$(basename $(cat /proc/cmdline | cut -f 4 -d \" \" | cut -f 2 -d \"=\"	|\
cut -f 1 -d \",\"))\n"
	for uml in conflist:
		str = str + "\
if [ \"$NODO\" = \"cow-%s\" ]\n\
then\n\
\thostname %s\n" % (conflist[uml].config.umid, conflist[uml].config.umid)
		
		str = str + conf_network(conflist[uml].config.networks, conflist[uml].config.type) + conf_daemons(conflist[uml].config.daemons)
		str = str + "fi\n"
	file = open("/usr/share/guml4mip/vm/guml4mip.conf", 'w');
	file.write(str)
	file.close()
	os.chmod('/usr/share/guml4mip/vm/guml4mip.conf', 0770)

class controller:
	def __init__(self, umid, directory):
		guml_debug.prn("New controller")
		self.config = config(umid, directory)
		self.running = False
		
	def start(self):
		if self.running:
			# I don't think so, Tim
			raise AlreadyRunning
		self.running = True
		self.console = console(self.config.command_line())
		self.console.connect('destroy', self.controller_dead)
		
		self.do_the_gui()

	def finished(self):
		"""Signal to the controller that the UML has finished."""
		self.running = False
		
	def hardhalt(self, widget, data = None):
		os.system("uml_mconsole %s halt >/dev/null" % self.config.umid)
		
	def ctrlaltdel(self, widget, data = None):
		os.system("uml_mconsole %s cad >/dev/null" % self.config.umid)

	def do_the_gui(self):
		textlabel = gtk.Label(self.config.name)
		self.label = gtk.EventBox()
		self.label.add(textlabel)
		self.label.connect('event', self.gimme_a_menu)
		self.label.set_visible_window(False)
		self.label.show()
		textlabel.show()

		self.menu = gtk.Menu()
		cad = gtk.MenuItem("CtrlAltDel")
		cad.connect('activate', self.ctrlaltdel)
		self.menu.append(cad)
		cad.show()
		hardhalt = gtk.MenuItem("Hard Halt")
		hardhalt.connect('activate', self.hardhalt)
		self.menu.append(hardhalt)
		hardhalt.show()

	def gimme_a_menu(self, widget, event):
		if event.type == gtk.gdk.BUTTON_PRESS and event.button == 3:
			self.menu.popup(None, None, None, event.button, event.time)

	def controller_dead(self, widget, data = None):
		self.running = False

class console(gtk.Notebook):
	def __init__(self, command_line):
		gtk.Notebook.__init__(self)
		self.append_page(uml_terminal(self, command_line), gtk.Label("Console"))
		self.show()
	
	def add_vt(self, pts, label):
		self.add_page_in_label_order(pts_terminal(self, pts), label)

	def add_page_in_label_order(self, widget, label_text):
		for i in range(self.get_n_pages()):
			nbwidget = self.get_nth_page(i)
			guml_debug.prn("Checking %s against %s" % (label_text, self.get_tab_label_text(nbwidget)))
			if label_text < self.get_tab_label_text(nbwidget):
				guml_debug.prn("Inserting")
				self.insert_page(widget, gtk.Label(label_text), i)
				return
		
		guml_debug.prn("Appending notebook page")
		# If we're here, then our new page belongs at the end of everything
		self.append_page(widget, gtk.Label(label_text))

	def close(self):
		guml_debug.prn("Closing console")
		self.destroy()

class terminal(gtk.HBox):
	def __init__(self, console, data):
		gtk.HBox.__init__(self)
		self.make_terminal()
		self.console = console
		self.vcre = re.compile("Virtual console (\d+) assigned device '(.*)'")

		self.run(data)

	def run(self, data):
		print "Pure virtual method called.  It's called subclassing, Matt, try it sometime"

	def make_terminal(self):
		self.terminal = vte.Terminal()
		self.terminal.set_emulation("xterm")
		self.terminal.set_font_from_string("Mono 8")
		self.terminal.set_scrollback_lines(1000)
		self.terminal.set_backspace_binding('ascii-backspace')
		self.terminal.set_size(200, 100)
		
		scrollbar = gtk.VScrollbar()
		scrollbar.set_adjustment(self.terminal.get_adjustment())
		self.pack_start(self.terminal, expand=True)
		self.pack_start(scrollbar, expand=False)
		self.show_all()
		
	def close(self, widget, data = None):
		guml_debug.prn("Closing terminal")
		self.destroy()

class uml_terminal(terminal):
	def run(self, cmd):
		os.putenv('TERM', 'xterm')
		(infd, self.pipe) = os.popen4(' '.join(cmd), 't', 0)
		self.input_watcher = gobject.io_add_watch(self.pipe, gobject.IO_IN, self.handle_input)
		self.close_watcher = gobject.io_add_watch(self.pipe, gobject.IO_HUP, self.handle_close)
		self.line_buffer = ""

	def handle_input(self, fd, cond):
		c = fd.read(1)

		if c == "\n":
			self.scan_for_pts()
			self.line_buffer = ""
			self.terminal.feed("\r")
		else:
			self.line_buffer = self.line_buffer + c
		
		self.terminal.feed(c)
		
		return True

	def scan_for_pts(self):
		matches = self.vcre.match(self.line_buffer)
		if matches:
			guml_debug.prn("Creating VC #%s on %s" % (matches.group(1), matches.group(2)))
			self.console.add_vt(matches.group(2), "VC #%s" % matches.group(1))
		
	def handle_close(self, fd, cond):
		guml_debug.prn("UML terminal HUPed")
		gobject.source_remove(self.input_watcher)
		gobject.source_remove(self.close_watcher)
		self.pipe.close()
		self.destroy()
		self.console.close()
		
		return False

class pts_terminal(terminal):
	def run(self, pts):
		self.pipe = open(pts, 'r+', 0)
		self.input_watcher = gobject.io_add_watch(self.pipe, gobject.IO_IN, self.handle_input)
		self.close_watcher = gobject.io_add_watch(self.pipe, gobject.IO_HUP, self.handle_close)

	def handle_input(self, fd, cond):
		c = fd.read(1)

		# Strange newline handling in VTE necessitates this hack
		if c == "\n":
			self.terminal.feed("\r")
		
		self.terminal.feed(c)
		
		return True

	def handle_output(self, widget, str, len):
		self.pipe.write(str)
		
	def handle_close(self, fd, cond):
		guml_debug.prn("VC terminal HUPed")
		gobject.source_remove(self.input_watcher)
		gobject.source_remove(self.close_watcher)
		self.pipe.close()
		self.destroy()
		self.console.close()
		
		return False

	def make_terminal(self):
		terminal.make_terminal(self)
		self.terminal.connect('child-exited', self.close)
		self.terminal.connect('commit', self.handle_output)

class config:
	def __init__(self, umid, directory):
		# Lo, verify, and he did give his attributes defaults, for such is the
		# path to Righteousness, lest thy AttributeErrors bite thee on the arse
		# and cause much wailing and gnashing of teeth.
		#            -- Book of Geeks, 4:2
		self.umid = umid
		self.disks = {}
		self.networks = {}
		self.daemons = {}
		self.name = ""
		self.mem = 32
		self.extraopts = ""
		self.type = ""

		cfg = self.readconfig(umid, directory)

	def readconfig(self, umid, directory):
		confdata = SafeConfigParser()
		confdata.read("%s/%s.conf" % (directory, umid))
	
		try:
			self.setgeneraloptions(self._tuples_to_dict(confdata.items("general")))
		except NoSectionError:
			print "No general section found for %s." % umid
			sys.exit(2)
		
		try:
			self.setdiskoptions(self._tuples_to_dict(confdata.items("disks")))
		except NoSectionError:
			# How the fsck do I leave an empty except block?
			xyzzy = 3.14159265

		try:
			self.setdaemonoptions(self._tuples_to_dict(confdata.items("daemons")))
		except NoSectionError:
			print "No daemons section found for %s" % umid
			sys.exit(2)
			
		for s in confdata.sections():
			if re.compile('^eth\d+$').match(s):
				self.setnetworkoptions(s, self._tuples_to_dict(confdata.items(s)), s)
		
	def setgeneraloptions(self, conf):
		try:
			self.name = conf['name']
		except KeyError:
			print "Fatal: failed to find a name for %s" % self.umid
			sys.exit(2)

		try:
			self.mem = conf['mem']
		except KeyError:
			self.mem = 32
		
		try:
			self.image = conf['image']
		except KeyError:
			self.image = ''
		
		try:
			self.extraopts = conf['extraopts']
		except KeyError:
			self.extraopts = ''

		try:
			self.type = conf['type']
		except KeyError:
			self.type = "node"

	def setnetworkoptions(self, devname, conf, interface):
		if conf['mac'] == 'random':
			idhash = md5.new()
			idhash.update(self.umid + interface)
			hash = idhash.hexdigest()
			conf['mac'] = 'fe:fd:%s:%s:%s:%s' % (hash[0:2], hash[2:4], hash[4:6], hash[6:8])

		data = { 'type': conf['type'],
		         'mac': conf['mac'] }
		
		try:
			data['socket'] = conf['socket']
		except KeyError:
			data['socket'] = '/tmp/net.ctl'

		try:
			data['vlan'] = conf['vlan']
		except KeyError:
			data['vlan'] = 1

		try:
			data['ip'] = conf['ip']
		except KeyError:
			data['ip'] = ""
		
		self.networks[devname] = data

	def setdiskoptions(self, conf):
		for k in conf.keys():
			if re.compile('^ubd\d+$').match(k):
				self.disks[k] = conf[k]
	
	def setdaemonoptions(self, conf):
		for k in conf.keys():
			if re.compile('^daemon\d+$').match(k):
				self.daemons[k] = conf[k]

	def command_line(self):
		return ["/usr/share/guml4mip/vm/linux.uml",
		        "mem=%sM" % self.mem,
		        "con=pts",
		        "con0=fd:0,fd:1",
		        "umid=%s" % self.umid] + self.blockdevscmdline() + self.networkcmdline() + [ self.extraopts ]

	def networkcmdline(self):
		cmdline = []
		
		for dev in self.networks.keys():
			cfg = self.networks[dev]
			
			
			cmdline.append("%s=%s,%s,,%s" % (dev, cfg['type'], cfg['mac'], cfg['socket']))
			
		return cmdline

	def blockdevscmdline(self):
		cmdline = []
		
		if len(self.disks) == 0:
			cmdline = [ "ubd0=%s" % self.image ]
		else:
			for k in self.disks.keys():
				cmdline.append("%s=/usr/share/guml4mip/vm/cow-%s,%s" % (k, self.umid, self.disks[k]))

		return cmdline
	
	def _tuples_to_dict(self, tuplelist):
		dict = {}
		
		for i in tuplelist:
			dict[i[0]] = i[1]

		return dict


class AlreadyRunning(Exception):
	def __init__(self, value = None):
		self.value = value
	
	def __str__(self):
		if self.value != None:
			return repr(self.value)
		else:
			return 'UML already running'
