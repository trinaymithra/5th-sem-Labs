#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include <errno.h>

// this program asks to check for palindrome, and to give number of occurences of vowels in the given string
int main() {
	int sockfd, server_port;
	struct sockaddr_in server;
	int len;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1){
		printf("Error in creating socket");
		exit(0);
	}

	printf("Enter server port number: \n");
	scanf("%d", &server_port);

	server.sin_family = AF_INET;
	server.sin_port = htons(server_port);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	bzero(&server.sin_zero, 8);
	while (1) {

		char buf[50];
		printf("Enter a string: (halt to exit)");
		scanf("%s", buf);

		len = sizeof(server);
		int sent = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&server, len);

		char sid[] = "halt";
		int ch;
		if ((ch = strcmp(sid, buf))==0) {
			close(sockfd);
		}
		int rcvd = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&server, &len);
		printf("%s\n", buf );

		int str_len;
		int rcvd = recvfrom(sockfd, &str_len, sizeof(int), 0, (struct sockaddr *)&server, &len);
		printf("Length of the string is %d\n", str_len);

		int arr[5];
		int rcvd = recvfrom(sockfd, arr, sizeof(arr), 0, (struct sockaddr *)&server, &len);
		printf("a appeared %d times\ne appeared %d times\ni appeared %d times\no appeared %d times\nu appeared %d times\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

	return 0;
}
