#!/usr/bin/env python

##############################################################################
# guml4mip: GUI UML Management for Mobile IP
#
# A simple GUI program to boot and manage one or more User-Mode Linux virtual
# machines.  Allows the user to boot a UML and shut it back down again.
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

import sys, os.path
sys.path.append('/usr/share/guml4mip')
import gtk, time, os, re
import uml, uml_switch

class TerminalWindow:
	def __init__(self):
		self.directory = self.getlastdirectory()

		buttons = self.makebuttons()
		winbox = gtk.VBox()
		winbox.set_spacing(5)
		winbox.pack_start(buttons, expand=False, fill=False)


		self.umllist = gtk.ListStore(str, str)
		self.umlpicklist = gtk.TreeView(self.umllist)
		self.col = gtk.TreeViewColumn('')
		self.umlpicklist.append_column(self.col)
		cell = gtk.CellRendererText()
		self.col.pack_start(cell, expand=True)
		self.col.add_attribute(cell, 'text', 0)


		umlpicklist_scroller = gtk.ScrolledWindow()
		umlpicklist_scroller.set_policy(gtk.POLICY_NEVER,
						gtk.POLICY_AUTOMATIC)
		umlpicklist_scroller.set_size_request(250, 500)
		umlpicklist_scroller.add(self.umlpicklist)


		umlpicklist_align = gtk.Alignment(0, 0, 0, 0)
		umlpicklist_align.add(umlpicklist_scroller)

		self.umltabs = gtk.Notebook()
		self.umltabs.connect('button-press-event', self.clickhandler)
		
		mainbox = gtk.HBox()
		mainbox.pack_start(umlpicklist_align, expand=True)
		mainbox.pack_start(self.umltabs, expand=True)
		
		winbox.pack_start(mainbox, expand=True)
		
		self.window = gtk.Window()
		self.window.set_title("guml4mip - GUI UML Management for Mobile IP")
		self.window.set_border_width(10)
		self.window.add(winbox)
		self.window.connect('destroy', self.shutdown)
		self.window.set_default_size(800,500)
		
		self.window.show_all()

		self.listscenario()

		self.switch = uml_switch.UmlSwitchWindow(self.configured_umls)
		self.switch.start()

	def listscenario(self):
		self.configured_umls = uml.list(self.directory)
		
		self.umllist.clear()
		for u in self.configured_umls.keys():
			umlname = self.configured_umls[u].config.name
			self.umllist.append([umlname, u])

		scenario = re.split('/', self.directory)
		self.col.set_title('Scenario: %s' % scenario[len(scenario) - 1])

	def bootuml(self, widget, data = None):
		# Yep, Python's definitely simple...
		selected = self.umlpicklist.get_selection().get_selected()
		if selected[1] == None:
			errdialog = gtk.MessageDialog(self.window, 0, gtk.MESSAGE_ERROR, gtk.BUTTONS_OK,
			      "You must select a UML to boot from the list to the left")
			response = errdialog.run()
			errdialog.destroy()
			return
		umid = self.umllist.get_value(selected[1], 1)
		# Don't ask me what the fuck that all did.  I have no idea.  And I wrote
		# it about 5 minutes ago.

		umlctl = self.configured_umls[umid]
		try:
			umlctl.start()
		except uml.AlreadyRunning:
			errdialog = gtk.MessageDialog(self.window, 0, gtk.MESSAGE_ERROR, gtk.BUTTONS_OK,
			            "Selected UML is already running; please select it from the tablist")
			response = errdialog.run()
			errdialog.destroy()
			return
		self.umltabs.append_page(umlctl.console, umlctl.label)

		self.umltabs.show_all()

	def bootalluml(self, widget, data = None):
		for u in self.configured_umls.keys():
			umlctl = self.configured_umls[u]
			try:
				umlctl.start()
			except uml.AlreadyRunning:
				errdialog = gtk.MessageDialog(self.window, 0, gtk.MESSAGE_ERROR, gtk.BUTTONS_OK, "Selected UML %s is already running; please shutdown before")
				response = errdialog.run()
				errdialog.destroy()
				return
			self.umltabs.append_page(umlctl.console, umlctl.label)
			self.umltabs.show_all()

			time.sleep(1)
	
	def umlswitch(self, widget, data = None):
		if self.switch.stopthread.isSet() == False:
			errdialog = gtk.MessageDialog(self.window, 0, gtk.MESSAGE_ERROR, gtk.BUTTONS_OK,
			      "You must wait all UMLs connections in switch")
			response = errdialog.run()
			errdialog.destroy()
			return

		if self.switch.show == True:
			self.switch.window.show_all()
			return

		for u in self.configured_umls.keys():
			umid = self.configured_umls[u].config.umid
			networks = self.configured_umls[u].config.networks
			self.switch.add_node(umid, networks)

		self.switch.window.show_all()
		self.switch.show = True
		
	def loadscenario(self, widget, data = None):
		directory = gtk.FileChooserDialog("Load Scenario", None, gtk.FILE_CHOOSER_ACTION_SELECT_FOLDER, (gtk.STOCK_CANCEL, gtk.RESPONSE_CANCEL, gtk.STOCK_OPEN, gtk.RESPONSE_OK))
		directory.set_current_folder(self.directory)
		response = directory.run()
		if response == gtk.RESPONSE_OK:
			self.directory = directory.get_filename()
		elif response == gtk.RESPONSE_CANCEL:
			directory.destroy()
			return

		directory.destroy()
		file = open("%s/.guml4mip" %os.getenv("HOME"), 'w')
		file.write(self.directory)
		file.close()

		# shutdown UML images running and uml_switch
		for u in self.configured_umls.keys():
			if self.configured_umls[u].running == True:
				os.system("killall linux.uml; rm -f /usr/share/guml4mip/vm/cow-*")
				break;

		self.switch.stop()
		self.switch.window.destroy()

		# load new scenario and start uml_switch
		self.listscenario()

		self.switch = uml_switch.UmlSwitchWindow(self.configured_umls)
		self.switch.start()


	def clickhandler(self, widget, event = None):
		if event.button != 3:
			return

	def getlastdirectory(self):
		default = "/usr/share/doc/guml4mip/examples/mipv6"
		if os.path.isfile("%s/.guml4mip" % os.getenv("HOME")) == False:
			file = open("%s/.guml4mip" % os.getenv("HOME"), 'w')
			file.write(default)
			file.close()
			return default
			
		file = open("%s/.guml4mip" % os.getenv("HOME"))
		directory = file.read()
		file.close()
		return directory

	def makebuttons(self):
		bootbtn = gtk.Button("Boot!")
		bootbtn.connect('clicked', self.bootuml)

		bootallbtn = gtk.Button("Boot All")
		bootallbtn.connect('clicked', self.bootalluml)

		umlswitchbtn = gtk.Button("Uml Switch")
		umlswitchbtn.connect('clicked', self.umlswitch)
		
		loadscenario = gtk.Button("Load Scenario")
		loadscenario.connect('clicked', self.loadscenario)

		quitbtn = gtk.Button("Quit")
		quitbtn.connect('clicked', self.shutdown)

		buttons = gtk.HButtonBox()
		buttons.set_spacing(3)
		buttons.set_layout(gtk.BUTTONBOX_START)
		buttons.pack_start(bootbtn, expand=False)
		buttons.pack_start(bootallbtn, expand=False)
		buttons.pack_start(umlswitchbtn, expand=False)
		buttons.pack_start(loadscenario, expand=False)
		buttons.pack_start(quitbtn, expand=False)

		return buttons

	def shutdown(self, widget, data = None):
		for u in self.configured_umls.keys():
			if self.configured_umls[u].running == True:
				os.system("killall linux.uml; rm -f /usr/share/guml4mip/vm/cow-*")
				break;

		self.switch.stop()

		gtk.main_quit()

	def main(self):
		gtk.main()

if __name__ == "__main__":
	win = TerminalWindow()
	win.main()
