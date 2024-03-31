#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int main(void)
{
    int socket_desc;
    int timer, frame;
    struct sockaddr_in server_addr;
    char server_message[2000], client_message[2000];
    
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));
    
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc < 0)
    {
        printf("Unable to create socket\n");
        return -1;
    }
    printf("Socket created successfully\n");
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Unable to connect\n");
        return -1;
    }
    printf("Connected with server successfully\n");
    printf("Enter the total frames: ");
    scanf("%d", &frame);
    
    while (frame > 0)
    {
        
        memset(server_message, '\0', sizeof(server_message));
        memset(client_message, '\0', sizeof(client_message));
        printf("\nEnter frame message: ");
        scanf("%s", client_message);
        
    x:
        timer = 10;
        if (send(socket_desc, client_message, strlen(client_message), 0) < 0)
        {
            printf("Unable to send message\n");
            return -1;
        }
        
    y:
        if (timer > 0)
        {
            if (recv(socket_desc, server_message, sizeof(server_message), 0) < 0)
            {
                printf("Error while receiving server's msg\n");
                timer--;
                goto y;
            }
            if (strcmp(server_message, "N") == 0 || strcmp(server_message, "n") == 0)
            {
                printf("\nWaiting...");
                timer--;
                goto y;
            }

            if (strcmp(server_message, "Y") == 0 || strcmp(server_message, "y") == 0)
            {

                printf("\nServer acknowledged");
                timer = 0;
                frame--;
            }
        }
        else
        {

            printf("\nServer donot acknowledged\nResending....");

            goto x;
        }
    }
    close(socket_desc);
    return 0;
}