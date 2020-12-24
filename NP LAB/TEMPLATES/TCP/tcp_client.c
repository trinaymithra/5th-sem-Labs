#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>


int main() {

	int s, server_port;
	struct sockaddr_in server;
	int conn;
	int sb, rb;
	char rbuffer[100];

	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == -1) {
		printf("Socket not created\n");
		exit(0);
	}
	else 
		printf("Socket created\n\n");

	printf("Enter the port to be connected: ");
	scanf("%d", &server_port);

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(server_port);

	conn = connect(s, (struct sockaddr *) &server, sizeof(server));
	if (conn == -1 ){
		printf("Connection not created\n");
		exit(0);
	}
	else
		printf("Connected to server!\n\n");

	char sbuffer[] = "Hello from client!";
	sb = send(s, sbuffer, sizeof(sbuffer), 0);

	rb = recv(s, rbuffer, sizeof(rbuffer), 0);
	printf("Received message: %s\n", rbuffer);

	close(s);
	return 0;
}