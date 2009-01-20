#!/usr/bin/env python

##############################################################################
# guml: GUI UML Management Love
#
# A simple GUI program to boot and manage one or more User-Mode Linux virtual
# machines.  Allows the user to boot a UML and shut it back down again.
#
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
sys.path.append('./')
import gtk, time, os
import uml, uml_switch

class TerminalWindow:
	def __init__(self):
		buttons = self.makebuttons()
		winbox = gtk.VBox()
		winbox.set_spacing(5)
		winbox.pack_start(buttons, expand=False, fill=False)

		self.configured_umls = uml.list()

		self.umllist = gtk.ListStore(str, str)
		for u in self.configured_umls.keys():
			umlname = self.configured_umls[u].config.name
			self.umllist.append([umlname, u])

		self.umlpicklist = gtk.TreeView(self.umllist)
		col = gtk.TreeViewColumn('Available UMLs')
		self.umlpicklist.append_column(col)
		cell = gtk.CellRendererText()
		col.pack_start(cell, expand=True)
		col.add_attribute(cell, 'text', 0)

		umlpicklist_scroller = gtk.ScrolledWindow()
		umlpicklist_scroller.set_policy(gtk.POLICY_NEVER,
						gtk.POLICY_AUTOMATIC)
		umlpicklist_scroller.set_size_request(150, 500)
		umlpicklist_scroller.add(self.umlpicklist)
		umlpicklist_align = gtk.Alignment(0, 0, 0, 0)
		umlpicklist_align.add(umlpicklist_scroller)
		self.umltabs = gtk.Notebook()
		self.umltabs.connect('button-press-event', self.clickhandler)
		
		mainbox = gtk.HBox()
		mainbox.pack_start(umlpicklist_align)
		mainbox.pack_start(self.umltabs, expand=False)
		
		winbox.pack_start(mainbox, expand=False)
		
		self.window = gtk.Window()
		self.window.set_border_width(10)
		self.window.add(winbox)
		self.window.connect('destroy', self.shutdown)
		self.window.set_default_size(800,500)
		
		self.window.show_all()
		
		self.switch = uml_switch.UmlSwitchWindow(self.configured_umls)
		self.switch.start()

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

		for u in self.configured_umls.keys():
			umid = self.configured_umls[u].config.umid
			networks = self.configured_umls[u].config.networks
			self.switch.add_node(umid, networks)

		self.switch.window.show_all()
		

	def editumlconf(self, widget, data = None):
		# blah
		x = 1
	
	def makenewuml(self, widget, data = None):
		#bling
		x = 1

	def clickhandler(self, widget, event = None):
		if event.button != 3:
			return
		
		

	def makebuttons(self):
		bootbtn = gtk.Button("Boot!")
		bootbtn.connect('clicked', self.bootuml)

		bootallbtn = gtk.Button("Boot All")
		bootallbtn.connect('clicked', self.bootalluml)

		umlswitchbtn = gtk.Button("Uml Switch")
		umlswitchbtn.connect('clicked', self.umlswitch)

#		editbtn = gtk.Button("Edit")
#		editbtn.connect('clicked', self.editumlconf)
#		buttons.pack_start(editbtn, expand=False)
#		
#		newbtn = gtk.Button("New UML")
#		newbtn.connect('clicked', self.makenewuml)
#		buttons.pack_start(newbtn, expand=False)

		quitbtn = gtk.Button("Quit")
		quitbtn.connect('clicked', self.shutdown)

		buttons = gtk.HButtonBox()
		buttons.set_spacing(3)
		buttons.set_layout(gtk.BUTTONBOX_START)
		buttons.pack_start(bootbtn, expand=False)
		buttons.pack_start(bootallbtn, expand=False)
		buttons.pack_start(umlswitchbtn, expand=False)
		buttons.pack_start(quitbtn, expand=False)

		return buttons

	def shutdown(self, widget, data = None):
		for u in self.configured_umls.keys():
			if self.configured_umls[u].running == True:
				os.system("killall linux.uml; rm -f /usr/share/guml/vm/cow-*")
				break;

		self.switch.stop()

		gtk.main_quit()

	def main(self):
		gtk.main()

if __name__ == "__main__":
	win = TerminalWindow()
	win.main()
