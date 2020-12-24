#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main () {
	int s, server_port, conn;
	struct sockaddr_in server, client;

	s = socket(AF_INET, SOCK_DGRAM, 0);
	if (s == -1){
		printf("Socket not created\n");
		exit(0);
	}
	else
		printf("Socket created successfully\n\n");

	printf("Enter the port to be connected: ");
	scanf("%d", &server_port);

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(server_port);

	conn = bind(s, (struct sockaddr *) &server, sizeof(server));
	if (conn == -1 ){
		printf("Binding error.\n");
		exit(0);
	}
	else
		printf("Port is binded to socket!\n\n");
	int sb, rb;
	char sbuffer[100], rbuffer[100];
	int cli_len;

	rb = recvfrom(s, rbuffer, sizeof(rbuffer), 0, (struct sockaddr *) &client, &cli_len);
	printf("Received message: %s\n", rbuffer);

	int i=0;
	while(1) {
		sbuffer[i] =rbuffer[i];
		i++;
		if(rbuffer[i-1] == '\0')
			break;
	}

	printf("Message to be sent is %s\n", sbuffer);
	sb = sendto(s, sbuffer, sizeof(sbuffer), 0, (struct sockaddr *) &client, sizeof(client));
	if( sb == -1){
		printf("Message could not be sent\n");
	}
	return 0;
}