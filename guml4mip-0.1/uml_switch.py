#!/usr/bin/env python

# example notebook.py

import gtk, socket, os, re, time
import threading 

gtk.gdk.threads_init()

class UmlSwitchWindow(threading.Thread):

	def __init__(self, umls):
		threading.Thread.__init__(self)
		self.umls = umls
		self.vlans = self.get_vlans()
		self.devs = self.get_devs()
		self.start_uml_switch()
		self.sock = self.connect_uml_switch()
		self.nodes = []
		self.show = False

		self.stopthread = threading.Event()

		# create Window for uml_switch
		self.window = gtk.Window(gtk.WINDOW_TOPLEVEL)
		self.window.set_title("guml4mip - uml switch")
		self.window.connect("delete_event", self.delete)
		self.window.set_border_width(10)

		table = gtk.Table(3,6,False)
		self.window.add(table)

        # Create a new notebook, place the position of the tabs
		self.notebook = gtk.Notebook()
		self.notebook.set_tab_pos(gtk.POS_LEFT)
		table.attach(self.notebook, 0,6,0,1)
		self.notebook.show()
		self.show_tabs = True
		self.show_border = True

        # Create a bunch of buttons
		button = gtk.Button("close")
		button.connect("clicked", self.delete)
		table.attach(button, 0,1,1,2)
		button.show()

		table.show()
		self.window.set_default_size(40,10)
#		self.window.show_all()

	def run(self):
		connections = []

		namematch = re.compile('^([0-9]+)\t([0-9a-fA-Z]+:[0-9a-fA-Z]+:[0-9a-fA-Z]+:[0-9a-fA-Z]+:[0-9a-fA-Z]+:[0-9a-fA-Z]+)')

		while not self.stopthread.isSet():

			gtk.threads_enter()
			self.sock.send('list\n')
			line = self.sock.recv(600)
			gtk.threads_leave()

			line =  line.splitlines()
			for i in line:
				matches = namematch.match(i)
				if matches != None:
					port = matches.group(1)
					mac = matches.group(2)
				else:
					break
				
				if self.search_list(connections, mac):
					# connect uml_image in your vlan
					host = self.get_host(mac)
					if host == None:
						break
					dev = self.get_interface(host, mac)
					vlan = host.config.networks[dev]['vlan']

					self.sock.send('move %s %s\n' %(port, str(vlan)))
					a = self.sock.recv(100)
					print host.config.umid + a
					connections.append(mac)
					self.nodes.append([host.config.umid, dev, port])
					if self.devs == len(connections):
						self.stopthread.set()

			time.sleep(0.1)

	def stop(self):
		self.stopthread.set()
		self.sock.send('quit\n')
		self.sock.close

	def delete(self, widget, event=None):
		self.window.hide_all()
		return False

	def callback(self, widget, data=None):
		print "%s was toggled %s" % (data, ("OFF", "ON")[widget.get_active()])
		if widget.get_active() == 1:
			for umid in self.nodes:
				if umid[0] == data[0] and umid[1] == data[1]:
					self.sock.send('move %s %s\n' %(umid[2], str(data[2])))
					print 'move %s %s' %(umid[2], data[2])
					a = self.sock.recv(100)


	def add_node(self, umid, networks):
		vbox = gtk.VBox(False, 10)
		vbox.set_border_width(10)
		vbox.show()

		for dev in networks:

			vbox2 = gtk.VBox(False, 10)
			vbox2.set_border_width(10)
			vbox2.show()
			vbox.pack_start(vbox2, False, False, 0)

			hbox = gtk.HBox(False, 10)
			hbox.set_border_width(10)
			hbox.show()
			vbox2.pack_start(hbox, False, False, 0)

			label = gtk.Label(dev)
			label.show()
			hbox.pack_start(label, False, False, 0)

			button = gtk.RadioButton(None, "0")
			button.connect("toggled", self.callback, [umid , dev, '0'])
			hbox.pack_start(button, True, True, 0)
			button.show()

			for vlan in self.vlans:
				button = gtk.RadioButton(button, str(vlan))
				button.connect("toggled", self.callback, [umid, dev, vlan])
				if vlan == networks[dev]['vlan']:
					button.set_active(True)
				hbox.pack_start(button, True, True, 0)
				button.show()


		label = gtk.Label(umid)
		self.notebook.insert_page(vbox, label, 1)

	def get_devs(self):
		devs = 0
		for u in self.umls.keys():
			networks = self.umls[u].config.networks
			for dev in networks.keys():
				devs = devs + 1
		return devs
				
	def get_vlans(self):
		vlans = []
		for u in self.umls.keys():
			networks = self.umls[u].config.networks
			for dev in networks.keys():
				if self.search_list(vlans, networks[dev]['vlan']):
					vlans.append(networks[dev]['vlan'])
		vlans.sort()
		return vlans

	def start_uml_switch(self):
		os.system("killall uml_switch_mobile; rm -r /tmp/net.ctl")
		os.system("/usr/bin/uml_switch_mobile -unix /tmp/net.ctl &")
		time.sleep(0.1)

	def connect_uml_switch(self):
		sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		sock.connect(('localhost', 7777))
		sock.recv(100)
		return sock

	
	def search_list(self, list, arg):
		for l in list:
			if l == arg:
				return False
		return True

	def get_host(self, mac):
		for u in self.umls.keys():
			networks = self.umls[u].config.networks
			for dev in networks.keys():
				if networks[dev]['mac'] == mac:
					return self.umls[u]

		return None

	def get_interface(self, host, mac):
		for dev in host.config.networks.keys():
			if host.config.networks[dev]['mac'] == mac:
				return dev
		return ""

