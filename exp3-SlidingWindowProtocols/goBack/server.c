#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void sendMessage(int sockfd, int ack) {
    char buff[MAX];
    sprintf(buff, "%d", ack);
    send(sockfd, buff, strlen(buff), 0);
}

int main() {
    int sockfd, connfd, len;
    struct sockaddr_in serveraddr, client;

    // Create socket
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket creation failed\n");
        exit(0);
    }
    else
        printf("socket created successfully\n");

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(PORT);

    if (bind(sockfd, (SA *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("Bind failed. Error");
        return 1;
    }
    printf("Bind done\n");

    listen(sockfd, 5);
    printf("server listening .. \n");

    len = sizeof(client);
    connfd = accept(sockfd, (SA *) &client, &len);

    char buff[MAX];
    int f, c, ack, next = 0;

    while(1) {
        sleep(1);
        memset(buff, 0, MAX);
        recv(connfd, buff, MAX, 0);

        if(strcmp("Exit", buff) == 0) {
            printf("exit\n");
            break;
        }

        f = atoi(buff);

        if(f != next) {
            printf("Frame %d discarded\n acknoledgement sent:%d\n", f, ack);
            sendMessage(connfd, ack);
            continue;
        }

        c = rand() % 3;

        switch(c) {
            case 0:
                printf("Frame %d not received\n", f);
                break;
            case 1:
                ack = f;
                sleep(2);
                printf("Frame %d received\nAcknowledgement sent:%d\n", f, ack);
                sendMessage(connfd, ack);
                next = ack + 1;
                break;
            case 2:
                ack = f;
                printf("Frame %d received\nAcknowledgement sent:%d\n", f, ack);
                sendMessage(connfd, ack);
                next = ack + 1;
                break;
        }
    }

    close(sockfd);

    return 0;
}
