/*
* gen-0.1
*   
* (c) 2008 Cleiber Marques
*      
* This program is free software; you can redistribute it and /or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version
* 2 of the License, or (at your option) any later version.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <getopt.h>

#define VERSION 0.1
#define PORT 4950
#define SIZE_PACK 100
#define TCP 1
#define UDP 0
#define IPV6

struct gen_config {
	char *ip;
	int protocol;
	int listen;
	int debug;
	unsigned long size;
	int time;
};

static void conf_usage(void)
{
	fprintf(stderr,
			"Uso: gen [opções]\nOpções:\n"
			"  -V, --version\t\tExibe informações sobre a versão\n"
			"  -?, -h, --help\tExibe informacões de ajuda\n"
			"  -l, --listen\t\tColoca o programa em modo de escuta para receber fluxo de dados\n"
			"  -d, --debug\t\tHabilita a opção de debug\n"
			"  -p <tcp|udp>\t\tConfigura qual protocolo de transporte irá usar\n"
			"  -s <tamanho>\t\tConfigura o tamanho do pacote a ser enviado\n"
			"  --ip <endereço IP>\tConfigura o ip para onde enviará o fluxo de dados\n");
			
}

static void conf_version(void)
{
	fprintf(stderr, "gen v%s\nAutor: Cleiber Marques da Silva <cleiber.dev@gmail.com\n", VERSION);
}

static int conf_cmdline(struct gen_config *cfg, int argc, char **argv)
{
	static struct option long_opts[] = {
		{"version", 0, 0, 'V'},
		{"help", 0, 0, 'h'},
		{"listen", 0, 0, 'l'},
		{"debug", 0, 0, 'd'},
		{0, 0, 0, 0}
	};

	while(1) {
		int idx, c;
		c = getopt_long(argc, argv, "a:p:s:t:Vh?ld", long_opts, &idx);
		if (c == -1)
			break;

		switch (c) {
		case 'a':
			cfg->ip = optarg;
			break;
		case 'V':
			conf_version();
			return -1;
		case '?':
		case 'h':
			conf_usage();
			return -1;
		case 'l':
			cfg->listen = 1;
			break;
		case 'd':
			cfg->debug = 1;
			break;
		case 's':
			cfg->size = atoi(optarg);
			break;
		case 'p':
			if (strcmp(optarg, "tcp") == 0) {
				cfg->protocol = TCP;
				break;
			} else if (strcmp(optarg, "udp") == 0) {
				cfg->protocol = UDP;
				break;
			} else {
				printf("Erro ao configurar protocolo de transporte %s\n", optarg);
				return -1;
			}
		case 't':
			cfg->time = 0;
			break;
		default:
			printf("Error %s", optarg);
			break;
		}
	}
	return 0;
}

int main(int argc, char **argv)
{
	struct gen_config cfg;
	struct tm *local;
	time_t t;
	int fd, fd_rcv, len;
	unsigned long numbytes, count = 0, i = 0;
	#ifdef IPV6
	struct sockaddr_in6 gen, rcv;
	char addr[INET6_ADDRSTRLEN];
#else
	struct sockaddr_in gen, rcv;
#endif

	cfg.listen = 0;
	cfg.debug = 0;
	cfg.protocol = UDP;
	cfg.size = SIZE_PACK;
	cfg.time = 1;

	if(conf_cmdline(&cfg, argc, argv) < 0)
		return 1;

	/* Criando socket */
#ifdef IPV6
	printf("Program version IPv6\n");
	if (!(fd = socket(AF_INET6, cfg.protocol ? SOCK_STREAM : SOCK_DGRAM, 0))) {
#else
	printf("Program version IPv4\n");
	if (!(fd = socket(AF_INET, cfg.protocol ? SOCK_STREAM : SOCK_DGRAM, 0))) {
#endif
		fprintf(stderr, "Error in create socket\n");
		return 1;
	}
	bzero(&gen, sizeof(gen));
#ifdef IPV6
	gen.sin6_family = AF_INET6;
	gen.sin6_port = htons(PORT);
#else
	gen.sin_family = AF_INET;
	gen.sin_port = htons(PORT);
#endif
	unsigned long buf[cfg.size];

	if(cfg.listen) {
		int sec;
#ifdef IPV6
		gen.sin6_addr = in6addr_any;
#else
		gen.sin_addr.s_addr = INADDR_ANY;
#endif

		/* Bind */
		if (bind(fd, (struct sockaddr *)&gen, sizeof(gen)) == -1) {
			fprintf(stderr, "Erro: em bind\n");
			return 1;
		}

		/* Listen e Accept somente ser for TCP */
		if(cfg.protocol == TCP){
			listen(fd, 5);
			if((fd_rcv = accept(fd, (struct sockaddr *)&rcv, &len)) < 0) {
				fprintf(stderr, "Erro: em accept\n");
				return 1;
			}
		}
		
		t = time(NULL);
		local = localtime(&t);
		sec = local->tm_sec;
		while(1) {
			len = sizeof(rcv);

			/* Recebendo pacote */
			if(cfg.protocol) {
				/* TCP */
				if ((numbytes = recvfrom(fd_rcv, buf, sizeof(buf), 0, (struct sockaddr *)&rcv, &len)) < 1) {
				   	fprintf(stderr,"Erro: em recvfrom\n");
    				break;
  				}
			} else {
				/* UDP */
				if ((numbytes = recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr *)&rcv, &len)) == -1) {
				   	fprintf(stderr,"Erro: em recvfrom\n");
    				break;
  				}
			}
			
			if(count == buf[0])
				count++;	
			else {
				count = buf[0];
				i++;
			}

			t = time(NULL);
			local = localtime(&t);
			if(local->tm_sec != sec) {
				printf("Pacotes perdidos: %d\nBanda: %d\n", i, (count - i) * sizeof(buf));
				i=0;
				sec = local->tm_sec;
			}

			/* Pega a hora do sistema e imprime o log, se debug habilitado */
			if(cfg.debug) {
#ifdef IPV6
			inet_ntop(AF_INET6, &rcv.sin6_addr, addr, sizeof(addr));
			printf("Gen recebido [%d:%d:%d] %d bytes de %s seq=%d\n", local->tm_hour, local->tm_min, local->tm_sec, numbytes, addr, buf[0]);
#else
			printf("Gen recebido [%d:%d:%d] %d bytes de %s seq=%d\n", local->tm_hour, local->tm_min, local->tm_sec, numbytes, inet_ntoa(rcv.sin_addr), buf[0]);
#endif
			}
			//close(fd_rcv);
		}
	} else {
#ifdef IPV6
		inet_pton(AF_INET6, cfg.ip, &gen.sin6_addr);
#else
		inet_pton(AF_INET, cfg.ip, &gen.sin_addr);
#endif
		/* Connect somente se for tcp*/
		if(cfg.protocol == TCP) {
			if(connect(fd, (struct sockaddr *)&gen, sizeof(gen)) < 0) {
				fprintf(stderr, "Erro: em connect\n");
				return 1;
			}
		}

		while(1) {
			srand(time(NULL));

			buf[0] = count++;
			/* Completa o pacote com numeros randomicos */
			for(i=1; i<cfg.size; i++)
				buf[i] = rand() % 10; 
			
			/* Envia pacote */
			if ((numbytes = sendto(fd, buf, sizeof(buf), 0, (struct sockaddr *)&gen, sizeof(gen))) == -1) {
    			fprintf(stderr, "Erro: em sendto\n");
    			/*return 1;*/
 		 	}

			/* Pega a hora do sistema e imprime o log, se debug habilitado  */
			if(cfg.debug) {
				t = time(NULL);
				local = localtime(&t);
				printf("Gen enviando [%d:%d:%d] %d bytes para %s seq=%d\n", local->tm_hour, local->tm_min, local->tm_sec, numbytes, cfg.ip, buf[0]);
			}
			sleep(cfg.time);
		}
	}
}

