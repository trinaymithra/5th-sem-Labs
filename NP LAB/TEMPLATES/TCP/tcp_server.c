#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main() {

	int s, server_port, new_sock, cli_len;
	struct sockaddr_in server, client;
	int conn;
	int sb, rb;
	char rbuffer[100], sbuffer[100];

	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == -1) {
		printf("Socket not created\n");
		exit(0);
	}
	else 
		printf("Socket created\n\n");

	printf("Enter the port to be connected: \n");
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

	conn = listen(s, 1);
	if (conn == -1 ){
		printf("Listen Error\n");
		exit(0);
	}
	else
		printf("Server is listening!!\n\n");

	new_sock = accept(s, (struct sockaddr *) &client, &cli_len);

	rb = recv(new_sock, rbuffer, sizeof(rbuffer), 0);
	printf("Received message: %s\n", rbuffer);

	int i=0;

	while (1) {
		sbuffer[i] = rbuffer[i];
		i++;
		if (rbuffer[i-1] == '\0')
			break;
	}
	sb = send(new_sock, sbuffer, sizeof(sbuffer), 0);
	close(s);
	return 0;
}