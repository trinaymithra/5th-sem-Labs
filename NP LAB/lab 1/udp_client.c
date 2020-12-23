#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>


int main() {
	int sockfd, server_port;
	struct sockaddr_in server;
	int len,ch, str_len;
	char buf[50];
	int sent, rcvd;;
	int arr[5];

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1){
		printf("Error in creating socket");
		exit(0);
	}
	else
		printf("Socket created successfully\n");

	printf("Enter server port number: \n");
	scanf("%d", &server_port);

	server.sin_family = AF_INET;
	server.sin_port = htons(server_port);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	bzero(&server.sin_zero, 8);

	while (1) {

		printf("Enter a string: (halt to exit)");
		scanf("%s", buf);

		len = sizeof(server);
		sent = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&server, len);//sending string to server

		ch = strcmp("halt", buf);
		if (ch == 0) {
			printf("Halting the connection.\n");
			close(sockfd);
			break;
		}

		//receive palindrome output
		rcvd = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&server, &len);
		printf("%s\n", buf);

		//receive string length
		rcvd = recvfrom(sockfd, &str_len, sizeof(int), 0, (struct sockaddr *)&server, &len);
		printf("Length of the string is %d\n", str_len);

		//receive occurences of vowels
		rcvd = recvfrom(sockfd, arr, sizeof(arr), 0, (struct sockaddr *)&server, &len);
		printf("\nOccurences of vowels:\n'a' appeared %d times\n'e' appeared %d times\n'i' appeared %d times\n'o' appeared %d times\n'u' appeared %d times\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
	}
	return 0;
}