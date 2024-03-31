#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int main()
{
    int socket_desc, client_sock, client_size, frame;
    struct sockaddr_in server_addr, client_addr;
    char server_message[2000], client_message[2000];
    
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));
    
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc < 0)
    {
        printf("Error while creating socket\n");
        return -1;
    }
    printf("Socket created successfully\n");
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if (bind(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Couldn't bind to the port\n");
        return -1;
    }
    printf("Done with binding\n");
    
    if (listen(socket_desc, 1) < 0)
    {
        printf("Error while listening\n");
        return -1;
    }
    printf("\nListening for incoming connections.....\n");
    
    client_size = sizeof(client_addr);
    client_sock = accept(socket_desc, (struct sockaddr *)&client_addr, &client_size);
    if (client_sock < 0)
    {
        printf("Can't accept\n");
        return -1;
    }

    printf("Client connected at IP: %s and port: %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
    while (1)
    {
        
        if (recv(client_sock, client_message, sizeof(client_message), 0) < 0)
        {
            printf("Couldn't receive\n");
            return -1;
        }
        printf("Msg from client: %s\n", client_message);
        
        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));
        printf("\nServer Acknowledges or not:? Ack-Y or y, NACK- N or n");
    z:
        memset(server_message, '\0', sizeof(server_message));
        scanf("%s", server_message);
        
        if (send(client_sock, server_message, strlen(server_message), 0) < 0)
        {
            printf("Can't send\n");
            return -1;
        }
        if (strcmp(server_message, "N") == 0 || strcmp(server_message, "n") == 0)
        {
            printf("Acknowledgement not received by client");
            goto z;
        }
    }
    
    close(client_sock);
    close(socket_desc);
    return 0;
}