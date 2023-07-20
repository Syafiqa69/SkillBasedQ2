#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PORT 8484

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a specific address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started, listening on port %d\n", PORT);

    while (1) {
        printf("Waiting for a client to connect...\n");
        // Accept a client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_leng>
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.s>

        // Generate a random number between 100 and 999
        srand(time(NULL));
        int random_number = rand() % 900 + 100;

        // Send the random number to the client
        send(client_socket, &random_number, sizeof(random_number), 0);

        close(client_socket);
    }
                                                                    
    close(server_socket);
    return 0;
}

