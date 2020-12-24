#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main () {
	int s, server_port;
	struct sockaddr_in server;

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
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(server_port);

	int sb, rb;
	char sbuffer[100], rbuffer[100];

	printf("Enter a string to send: ");
	scanf("%s", sbuffer);

	sb = sendto(s, sbuffer, sizeof(sbuffer), 0, (struct sockaddr *) &server, sizeof(server));
	printf("Message sent\n");
	int ser_len;
	rb = recvfrom(s, rbuffer, sizeof(rbuffer), 0, (struct sockaddr *) &server, &ser_len);
	if (rb == -1) {
		printf("Message not received\n");
	}
	printf("Received message: %s\n", rbuffer);
	return 0;
}