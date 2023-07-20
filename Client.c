#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8484

int main() {
    int client_socket;
    struct sockaddr_in server_address;

    // Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Prepare server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("192.168.248.134"); //Server IP address
    server_address.sin_port = htons(PORT);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    int random_number;
    // Receive the random number from the server
    if (recv(client_socket, &random_number, sizeof(random_number), 0) < 0) {
        perror("Error receiving data from server");
        exit(EXIT_FAILURE);
    }

    // Display the random number
    printf("Random number received from the server: %d\n", random_number);

    close(client_socket);
    return 0;
}
