/*
 * Cliente.c
 *
 *  Created on: Mar 6, 2019
 *      Author: oracle
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "PropClient.h"
#include "Utils.h"

int main(){

	int sockfd, portno, n;

	    struct sockaddr_in serv_addr;
	    struct hostent *server;
	    char buffer[256];
	    log("definicion de variables");
	    sockfd = socket(AF_INET, SOCK_STREAM, 0);
	    if (sockfd < 0)
	        error("ERROR opening socket");
	    log("Abriendo socket");
	    server = gethostbyname(HOSTNAME);
	    if (server == NULL) {
	        fprintf(stderr,"ERROR, no such host\n");
	        exit(0);
	    }
	    log("definiendo hostname");
	    bzero((char *) &serv_addr, sizeof(serv_addr));
	    serv_addr.sin_family = AF_INET;
	    bcopy((char *)server->h_addr,
	         (char *)&serv_addr.sin_addr.s_addr,
	         server->h_length);
	    serv_addr.sin_port = htons(PORT);
	    log("inicializando socket addres");
	    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
	        error("ERROR connecting");
	    log("conexion");
	    printf("Please enter the message: ");
	    bzero(buffer,256);
	    fgets(buffer,255,stdin);
	    n = write(sockfd,buffer,strlen(buffer));
	    if (n < 0)
	         error("ERROR writing to socket");
	    log("leyyendo de socket");
	    bzero(buffer,256);
	    n = read(sockfd,buffer,255);
	    if (n < 0)
	         error("ERROR reading from socket");
	    printf("%s\n",buffer);
	return 0;
}
