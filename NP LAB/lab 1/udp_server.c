#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>

int main() {
	int sockfd;
	struct sockaddr_in server,client;
	int server_port, err_check;
	int n, i, ch, flag;
	int sent, rcvd;
	int client_size, len;
	char buf[50], opstr[50];
	int arr[] = {0,0,0,0,0};

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	printf("Socket created successfully \n\n");

	printf("Enter server's listening port number: \n");
	scanf("%d", &server_port);

	//complete details in server socket structure
	server.sin_family = AF_INET;
	server.sin_port = htons(server_port);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	bzero(&server.sin_zero, 8);

	err_check = bind(sockfd, (struct sockaddr *) &server, sizeof(server));
	printf("Binded successfully with local address\n\n");

	client_size = sizeof(client);
	len = sizeof(client);

	while(1) {

		//receive a string from the client
		rcvd = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&client, &len);
		printf("Received string is %s\n", buf);
		// check if the sent string is halt and exit
		buf[strlen(buf)] = '\0';
		ch = 0;
		ch = strcmp(buf, "halt");

		if (ch == 0) {
			printf("Halting the connection\n");
			close(sockfd);
			exit(0);	
		}

		//check for palindrome
		n = strlen(buf);
		flag = 1;
		for(i = 0; i < n/2; i++) {
			if(buf[i]!=buf[n-i-1]) {
				flag = 0;
				break;
			}
		}

		if (flag == 1) 
			strcpy(opstr,"Given string is a palindrome\n");
		else 
			strcpy(opstr,"Given string is not a palindrome\n");
		
		sent = sendto(sockfd, opstr, sizeof(opstr), 0, (struct sockaddr *)&client, client_size);

		//sending length of given string to client
		sent = sendto(sockfd, &n, sizeof(int), 0, (struct sockaddr *) &client, client_size);

		//calculating occurences of vowels in the string
		for (i=0; i<n; i++){
			switch (buf[i]) {
				case 'a' : arr[0]+=1;
						   break;
				case 'e' : arr[1]+=1;
						   break;
				case 'i' : arr[2]+=1;
						   break;
				case 'o' : arr[3]+=1;
						   break;
				case 'u' : arr[4]+=1;
						   break;
			}
		}
		sent = sendto(sockfd, arr, sizeof(arr), 0, (struct sockaddr *) &client, client_size);
		for (i = 0; i<n; i++)
			arr[i] = 0;
	}
	return 0;
}