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

commands = {1: ["dd if=/dev/zero of=fs.img bs=1024 seek=400k count=1",
	"mkfs.ext3 fs.img",
	"modprobe loop",
	"mount -o loop fs.img /mnt",
	"debootstrap --exclude=alpha,beta --variant=minbase --arch i386 lenny /mnt http://debian.c3sl.ufpr.br/debian/",
	"cp -r /usr/share/guml4mip/pkg /mnt/pkg"],
	2:[],
	3: ["echo -e \"/dev/ubd0 / ext3 defaults 0 1\" > /etc/fstab",
	"echo -e \"proc /proc proc defaults 0 0\" >> /etc/fstab",
	"echo -e \"uml\" > /etc/hostname",
	"echo -e \"127.0.0.1 localhost uml\" > /etc/hosts",
	"sed -i '/tty[2-6]/ s/^/#/g' /etc/inittab",
	"mkdir /host",
	"echo -e \"mount none /host -t hostfs -o /usr/share/guml4mip/vm\n/host/guml4mip.conf\" > /etc/rc.local",
	"apt-get purge exim4",
	"rm -rf /var/cache/apt/archives/*"]}

packages = {"network": "net-tools iputils-ping iproute iptables quagga dhcp3-client tcpdump",
		"devel": "build-essential indent automake flex bison", 
		"general": "debian-keyring debian-archive-keyring vim-tiny wget man-db libtool", 
		"our": "/pkg/mipv6-daemon-umip_0.4-1_i386.deb /pkg/radvd-hmip_0.7.2-1_i386.deb"}

def exec_commands(list):
	for command in list:
		print command
		if os.system(command) != 0:
			print "Error to create filesystem !!!"
#			os.system("umount /mnt")
#			os.system("rm fs.img")
			sys.exit(1)
	
if __name__ == "__main__":
	if os.path.isfile("/usr/share/guml4mip/vm/lenny.img") == True:
		print "File system already exists. Thanks !!!"
		sys.exit(0)

	print "File system image GNU/Linux Debian Lenny doesn't exist !!!"
	response = raw_input("Create a file system image GNU/Linux Debian Lenny. This may take a long time [y]:")

	if not (response == 'y' or response == ''):
		sys.exit(1)

	for task in commands.keys():
		list = commands[task]
		if task == 2:
			print "chroot /mnt"
			os.chroot('/mnt')
			for pack in packages.keys():
				if pack == 'our':
					list.append("dpkg -i %s" %packages[pack])
				else:
					list.append("apt-get install %s" % packages[pack])
		exec_commands(list)
	sys.exit(0)

