#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>

int main() {
	int sock_fd, new_sock, len;
	struct sockaddr_in server,client;
	int server_port;
	int err_check;
	int n, choice, i, ele;
	int sent, rcvd;

	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (sock_fd == -1) {
		printf("Socket error\n");
		exit(0);
	}
	else
		printf("Socket created successfully\n\n");

	printf("Enter server's listening port number: \n");
	scanf("%d", &server_port);

	//complete details in server socket structure
	server.sin_family = AF_INET;
	server.sin_port = htons(server_port);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	bzero(&server.sin_zero, 8);
	//printf("hello\n");

	err_check = bind(sock_fd, (struct sockaddr *) &server, sizeof(server));
	if (err_check == -1) {
		printf("Bind error ");
		exit(0);
	}	
	else
		printf("SOcket binded successfully\n\n");

	err_check = listen(sock_fd, 1);
	if (err_check == -1) {
		printf("Listen error: ");
		exit(0);
	}
	else
		printf("Socket is listening.\n\n");

	len = sizeof(client);
	new_sock = accept(sock_fd, (struct sockaddr *) &client, &len);

	while(1) {

		rcvd = recv(new_sock, &choice, sizeof(int), 0);

		rcvd = recv(new_sock, &n, sizeof(int), 0);

		int arr[n];
		rcvd = recv(new_sock, arr, sizeof(arr), 0);

		if (choice == 1 ) {//search for the element
			int flag = 0;
			rcvd = recv(new_sock, &ele, sizeof(int), 0);
			for (i = 0; i<n; i++) {
				if (ele == arr[i]) {
					sent = send(new_sock, &i, sizeof(int), 0);
					flag = 1;
					printf("Element found\n");
					break;
				}
			}
			if (flag == 0) {
				i = -1;
				printf("Element not found\n");
				sent = send(new_sock, &i, sizeof(int), 0);
			}
		}

		else if (choice == 2) {//sort the array
			int key, j; 
    		for (i = 1; i < n; i++) { 
        		key = arr[i]; 
        		j = i - 1; 
        		while (j >= 0 && arr[j] > key) { 
            		arr[j + 1] = arr[j]; 
            		j = j - 1; 
        		} 
        		arr[j + 1] = key; 
			}
			printf("Array sorted.\n");
			sent = send(new_sock, arr, sizeof(arr), 0);
		}

		else if (choice == 3) {
			int odd=0, even=0;
			int odd_arr[n], even_arr[n];
			for (i=0; i<n; i++) {
				if (arr[i] % 2 == 0)
					even_arr[even++] = arr[i];
				else
					odd_arr[odd++] = arr[i];
			}
			printf("Array is split into odd and even arrays.\n");
			sent = send(new_sock, &odd, sizeof(int), 0);
			sent = send(new_sock, &even, sizeof(int), 0);
			sent = send(new_sock, odd_arr, sizeof(odd_arr), 0);
			sent = send(new_sock, even_arr, sizeof(even_arr), 0);
		}
		
		else if (choice == 4) {
			printf("Closing the connection.\n");
			close(new_sock);
			close(sock_fd);
			exit(0);
	
		}
	}

	return 0;
}