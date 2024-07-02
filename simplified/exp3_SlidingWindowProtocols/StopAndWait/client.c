#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(void)
{
    int client_socket, frame_count, timer;
    struct sockaddr_in server_addr;
    char server_response[2000], frame_message[2000];
    
    // Clear message buffers
    memset(server_response, '\0', sizeof(server_response));
    memset(frame_message, '\0', sizeof(frame_message));
    
    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // Set server address properties
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    // Connect to the server
    connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    
    printf("Connected to the server\n");
    printf("Enter the total number of frames: ");
    scanf("%d", &frame_count);
    
    while (frame_count > 0)
    {
        // Clear message buffers
        memset(server_response, '\0', sizeof(server_response));
        memset(frame_message, '\0', sizeof(frame_message));
        
        printf("Enter frame message: ");
        scanf("%s", frame_message);
        
        while (1)
        {
            timer = 10;
            
            // Send frame message to server
            send(client_socket, frame_message, strlen(frame_message), 0);
            
            while (timer > 0)
            {
                // Receive server response
                recv(client_socket, server_response, sizeof(server_response), 0);
                
                if (strcmp(server_response, "Y") == 0 || strcmp(server_response, "y") == 0)
                {
                    printf("Server acknowledged\n");
                    frame_count--;
                    break;
                }
                
                if (strcmp(server_response, "N") == 0 || strcmp(server_response, "n") == 0)
                {
                    printf("Waiting for acknowledgment...\n");
                    timer--;
                }
            }
            
            if (timer == 0)
            {
                printf("Server did not acknowledge. Resending...\n");
            }
            else
            {
                break;
            }
        }
    }
    
    // Close socket
    close(client_socket);
    
    return 0;
}
