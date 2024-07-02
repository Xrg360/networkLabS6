#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int server_socket, client_socket, client_size;
    struct sockaddr_in server_addr, client_addr;
    char server_response[2000], client_message[2000];
    
    // Clear message buffers
    memset(server_response, '\0', sizeof(server_response));
    memset(client_message, '\0', sizeof(client_message));
    
    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // Set server address properties
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    // Bind socket to the specified port and address
    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    
    // Listen for incoming connections
    listen(server_socket, 1);
    
    // Accept an incoming connection
    client_size = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_size);

    printf("Client connected at IP: %s and port: %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
    while (1)
    {
        // Receive message from client
        recv(client_socket, client_message, sizeof(client_message), 0);
        printf("Msg from client: %s\n", client_message);
      z:  
        // Clear message buffers
        memset(server_response, '\0', sizeof(server_response));
        memset(client_message, '\0', sizeof(client_message));
        
        // Prompt for server response
        printf("Server Acknowledges or not? Ack-Y or y, NACK- N or n: ");
        scanf("%s", server_response);
        
        // Send server response to client
        send(client_socket, server_response, strlen(server_response), 0);
        
        // If acknowledgment not received by client, prompt again
        if (strcmp(server_response, "N") == 0 || strcmp(server_response, "n") == 0)
        {
            printf("Acknowledgment not received by client\n");
            goto z;
        }
    }
    
    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}
