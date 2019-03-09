/*
 * Utils.c
 *
 *  Created on: Mar 4, 2019
 *      Author: oracle
 */
#include<stdio.h>
#include <sys/socket.h>
#include<errno.h>

/*int hostname_to_ip(char *hostname , char *ip) {

	int sockfd;
	struct addrinfo hints, *servinfo, *p;
	struct sockaddr_in *h;
	int rv;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; // use AF_INET6 to force IPv6
	hints.ai_socktype = SOCK_STREAM;

	if ( (rv = getaddrinfo( hostname , "http" , &hints , &servinfo)) != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the results and connect to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next)
	{
		h = (struct sockaddr_in *) p->ai_addr;
		strcpy(ip , inet_ntoa( h->sin_addr ) );
	}

	freeaddrinfo(servinfo); // all done with this structure
	return 0;
}*/

void error(char *msg)
{
    perror(msg);
    exit(1);
}

void log(char *msg){

	char *str = malloc(strlen(msg) + 2);
	strcpy(str, msg);
	strcat(str, "\n");
	printf(str);
}


