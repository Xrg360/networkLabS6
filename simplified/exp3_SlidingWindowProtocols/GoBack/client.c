#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void sendData(int sockfd, int totalFrames, int windowSize)
{
    char buffer[MAX];
    int ack, frameIndex = 0, n, sendStatus, windowStart = 0, windowEnd = windowSize - 1, retryFlag = 0;
    struct timeval timeout;
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout));

    while (1)
    {
        for (frameIndex = 0; frameIndex < totalFrames && frameIndex <= windowEnd; frameIndex++)
        {
            snprintf(buffer, sizeof(buffer), "%d", frameIndex);
            sendStatus = send(sockfd, buffer, sizeof(buffer), 0);
            printf("Frame %d sent\n", frameIndex);
        }

        while (1)
        {
            if (windowEnd - windowStart != windowSize - 1 && retryFlag == 0 && frameIndex != totalFrames)
            {
                snprintf(buffer, sizeof(buffer), "%d", frameIndex);
                sendStatus = send(sockfd, buffer, sizeof(buffer), 0);
                printf("Frame %d sent\n", frameIndex);
                windowEnd++;
                frameIndex++;
            }

            retryFlag = 0;
            n = recv(sockfd, buffer, MAX, 0);
            ack = atoi(buffer);

            if (n > 0)
            {
                if (ack + 1 == totalFrames)
                {
                    printf("Ack received %d\nEXIT\n", ack);
                    strcpy(buffer, "EXIT");
                    send(sockfd, buffer, sizeof(buffer), 0);
                    return;
                }

                if (ack == windowStart)
                {
                    windowStart++;
                    printf("Ack received %d\n", ack);
                }
            }
            else
            {
                printf("Ack not received for %d\nRESENDING ...\n", ack);
                for (int j = windowStart; j < totalFrames && j < windowStart + windowSize; j++)
                {
                    snprintf(buffer, sizeof(buffer), "%d", j);
                    sendStatus = send(sockfd, buffer, sizeof(buffer), 0);
                    printf("Frame %d sent\n", j);
                }
                retryFlag = 1;
            }
        }
    }
}

int main()
{
    int sockfd, totalFrames, windowSize;
    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    connect(sockfd, (SA *)&server, sizeof(server));

    printf("Enter the number of frames: ");
    scanf("%d", &totalFrames);
    printf("Enter the window size: ");
    scanf("%d", &windowSize);

    sendData(sockfd, totalFrames, windowSize);

    close(sockfd);

    return 0;
}
