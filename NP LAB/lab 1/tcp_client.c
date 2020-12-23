#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include <errno.h>

int main() {

	int sockfd, err_check;
	struct sockaddr_in server;
	int server_port;
	int choice, n, ele, i;
	int sent, rcvd;

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		printf("Socket creation error");
		exit(0);
	}
	else
		printf("Socket created successfully\n\n");

	printf("Enter server's port number: \n");
	scanf("%d", &server_port);

	//complete details in server socket structure
	server.sin_family = AF_INET;
	server.sin_port = htons(server_port);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	bzero(&server.sin_zero, 8);

	//make a connection with server
	if ((err_check = connect(sockfd, (struct sockaddr *)&server, sizeof(server))) == -1 ) {
		printf("Connection not created due to an error ");
		exit(0);
	}
	else
		printf("Connected established successfully\n\n");

	while(1) {
		printf("Options are: \n1-Search\n2-Sort\n3-Split\n4-Exit\nChoose an option: ");
		scanf("%d", &choice);

		sent = send(sockfd, &choice, sizeof(int), 0);
		if (sent == -1){
			printf("Error in sending the message");
			exit(0);
		}

		if (choice == 4) {
			printf("Closing the connection\n");
			close(sockfd);
			break;
		}

		printf("Enter number of elements in the array: ");
		scanf("%d", &n);

		int arr[n];
		for(i=0; i<n; i++) 
			scanf("%d", &arr[i]);

		sent = send(sockfd, &n, sizeof(int), 0);//sending the size of array

		sent = send(sockfd, arr, sizeof(arr), 0);//sending the array
			
		if (choice == 1) {
			int index;

			printf("Enter the element to be searched in the array: ");
			scanf("%d", &ele);
			sent = send(sockfd, &ele, sizeof(int), 0);

			rcvd = recv(sockfd, &index, sizeof(int), 0);
			if (rcvd == -1){
			printf("Error in receiving\n");
			exit(0);
			}

			if (index == -1)
				printf("Element not found in the array\n");
			else 
				printf("Element found at %d position\n", index);
		}

		else if (choice == 2) {
			int ret_arr[n];
			rcvd = recv(sockfd, ret_arr, sizeof(ret_arr), 0);

			for(i=0; i<n; i++)
				printf("%d\t", ret_arr[i]);
			printf("\n");
		}

		else if (choice == 3){
			int odd_arr[n];
			int even_arr[n];
			int odd, even;

			rcvd = recv(sockfd, &odd, sizeof(int), 0);
			rcvd = recv(sockfd, &even, sizeof(int), 0);

			rcvd = recv(sockfd, odd_arr, sizeof(odd_arr), 0);
			for(i=0; i<odd; i++)
				printf("%d\t", odd_arr[i]);
			printf("\n");

			rcvd = recv(sockfd, even_arr, sizeof(even_arr), 0);
			for(i=0; i<even; i++)
				printf("%d\t", even_arr[i]);
			printf("\n");
		}
	}
	return 0;	
}
	
	
