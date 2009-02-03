#!/usr/bin/env python

##############################################################################
# guml4mip: GUI UML Management for Mobile IP
#
# A simple GUI program to boot and manage one or more User-Mode Linux virtual
# machines.  Allows the user to boot a UML and shut it back down again.
#
# Copyright (C) 2005 Cleiber Marques da Silva
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

import sys, os

if __name__ == "__main__":

	if sys.argv[1] == 'install':
		if not os.path.isdir("/usr/share/guml4mip"):
			os.mkdir("/usr/share/guml4mip")

		if not os.path.isdir("/usr/share/doc/guml4mip"):
			os.mkdir("/usr/share/doc/guml4mip")

		os.system("cp guml4mip.py /usr/bin/guml4mip")
		os.system("cp create_fs.py /usr/bin/create_fs")
		os.system("cp -r uml.py uml_switch.py guml_debug.py dirs/vm dirs/pkg /usr/share/guml4mip")
		os.system("cp -r dirs/examples /usr/share/doc/guml4mip")
		os.system("dpkg -i pkg/uml-switch*")
		os.system("apt-get install debootstrap")
		if os.system("create_fs") != 0:
			print "Error in isntall"
			sys.exit(1)
		os.system("killall exim4 cron")
		os.system("umount /mnt")
		os.system("mv fs.img /usr/share/guml4mip/vm/lenny.img")
		print "Install Complete !!!"

	elif sys.argv[1] == 'remove':
		os.system("rm -rf /usr/bin/guml4mip /usr/bin/create_fs /usr/share/guml4mip /usr/share/doc/guml4mip")
		os.system("dpkg -r uml-switch*")
		print "Remove Complete !!!"

	else:
		print "Option Invalid"
		sys.exit(1)

