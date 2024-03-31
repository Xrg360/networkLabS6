#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <sys/time.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void sendData(int sockfd, int nf, int ws) {
    char buff[MAX];
    int ack, i = 0, n, k, w1 = 0, w2 = ws - 1, j, flag = 0;
    struct timeval timeout;
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;
    
    if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0)
        perror("setsockopt(SO_RCVTIMEO) failed");

    while(1) {
        for(i = 0; i < nf && i <= w2; i++) {
            snprintf(buff, sizeof(buff), "%d", i);
            k = send(sockfd, buff, sizeof(buff), 0);
            printf("Frame %d sent\n", i);
        }
        
        while(1) {
            if(w2 - w1 != ws - 1 && flag == 0 && i != nf) {
                snprintf(buff, sizeof(buff), "%d", i);
                k = send(sockfd, buff, sizeof(buff), 0);
                printf("Frame %d sent\n", i);
                w2++;
                i++;
            }
            
            flag = 0;
            n = recv(sockfd, buff, MAX, 0);
            ack = atoi(buff);
            
            if(n > 0) {
                if(ack + 1 == nf) {
                    printf("Ack received %d\nEXIT\n", ack);
                    strcpy(buff, "EXIT");
                    k = send(sockfd, buff, sizeof(buff), 0);
                    return;
                }
                
                if(ack == w1) {
                    w1++;
                    printf("Ack received %d\n", ack);
                }
            } else {
                printf("Ack not received for %d\nRESENDING ...\n", ack);
                
                for(j = w1; j < nf && j < w1 + ws; j++) {
                    snprintf(buff, sizeof(buff), "%d", j);
                    k = send(sockfd, buff, sizeof(buff), 0);
                    printf("Frame %d sent\n", j);
                }
                flag = 1;
            }
        }
    }
}

int main() {
    int sockfd, f, w;
    struct sockaddr_in server;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if(sockfd < 0) {
        printf("Socket creation failed\n");
        exit(0);
    }
    
    printf("Socket created\n");
    
    memset(&server, 0, sizeof(server));
    
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
    
    if(connect(sockfd, (SA*)&server, sizeof(server)) != 0) {
        printf("Connection failed\n");
        exit(0);
    }
    
    printf("Connected successfully\n");
    
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    
    printf("Enter the window size: ");
    scanf("%d", &w);
    
    sendData(sockfd, f, w);
    
    close(sockfd);
    
    return 0;
}
