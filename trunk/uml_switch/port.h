/* Copyright 2002 Jeff Dike
 * Licensed under the GPL
 */

#ifndef __PORT_H__
#define __PORT_H__

#include <sys/socket.h>
#include <sys/un.h>
#include "switch.h"

struct packet {
	struct {
		unsigned char dest[ETH_ALEN];
		unsigned char src[ETH_ALEN];
		unsigned char proto[2];
	} header;
	unsigned char data[1500];
};

struct port {
	struct port *next;
	struct port *prev;
	int control;
	int domain; //Filipe
	void *data;
	int data_len;
	unsigned char src[ETH_ALEN];
	void (*sender)(int fd, void *packet, int len, void *data);
};



extern int handle_port(int fd);
extern void close_port(int fd);
extern int setup_sock_port(int fd, struct sockaddr_un *name, int data_fd);
extern int setup_port(int fd, void (*sender)(int fd, void *packet, int len,
		void *data), void *data, int data_len);
extern void handle_tap_data(int fd, int hub);
extern void handle_sock_data(int fd, int hub);
extern int managemobile(int port, int domain);
extern struct port* get_head(void);

#endif
