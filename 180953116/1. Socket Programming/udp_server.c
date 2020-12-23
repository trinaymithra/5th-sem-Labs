#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include <errno.h>

// this program checks for palindrome, finds the length of the string and also returns the number of occurrences of each vowel in the string
int main() {
	int sockfd, new_sock, len;
	struct sockaddr_in server,client;
	int server_port;
	int err_check;
	int n, choice, i, ele;
	int sent, rcvd;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1) {
		perror("Socket: ");
		exit(0);
	}

	printf("Enter server's listening port number: \n");
	scanf("%d", &server_port);

	//complete details in server socket structure
	server.sin_family = AF_INET;
	server.sin_port = htons(server_port);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	bzero(&server.sin_zero, 8);

	err_check = bind(sockfd, (struct sockaddr *) &server, sizeof(server));
	if (err_check == -1) {
		perror("Bind error: ");
		exit(0);
	}	

	err_check = sizeof(client);
	len = sizeof(client);

	while(1) {
		char buf[50];
		rcvd = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&client, &len);

		char sid[] = "halt";
		ch = strcmp(buf, sid);
		if (ch == 0) {
			close(sockfd);
			break;	
		}

		n = strlen(str);
		int flag = 0
		for(i=0;i<n/2;i++) {
			if(buf[i]!=buf[n-i-1])
				return 0;
		}
		return 1;
		sent = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&client, err_check);
	}
	
	return 0;
}
