#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void sendMessage(int sockfd, int ack)
{
    char buffer[MAX];
    sprintf(buffer, "%d", ack);
    send(sockfd, buffer, strlen(buffer), 0);
}

int main()
{
    int sockfd, clientfd, clientLen;
    struct sockaddr_in serverAddr, clientAddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    bind(sockfd, (SA *)&serverAddr, sizeof(serverAddr));
    listen(sockfd, 5);

    clientLen = sizeof(clientAddr);
    clientfd = accept(sockfd, (SA *)&clientAddr, &clientLen);

    char buffer[MAX];
    int frame, ack, nextFrame = 0;

    while (1)
    {
        sleep(1);
        memset(buffer, 0, MAX);
        recv(clientfd, buffer, MAX, 0);

        if (strcmp("Exit", buffer) == 0)
        {
            break;
        }

        frame = atoi(buffer);

        if (frame != nextFrame)
        {
            printf("Frame %d discarded\n acknoledgement sent:%d\n", frame, ack);
            sendMessage(clientfd, ack);
            continue;
        }

        int randomChoice = rand() % 3;

        switch (randomChoice)
        {
        case 0:
            printf("Frame %d not received\n", frame);
            break;
        case 1:
        case 2:
            ack = frame;
            printf("Frame %d received\nAcknowledgement sent:%d\n", frame, ack);
            sendMessage(clientfd, ack);
            nextFrame = ack + 1;
            break;
        }
    }

    close(sockfd);

    return 0;
}
             