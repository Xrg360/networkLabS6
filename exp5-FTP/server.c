#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
main()
{
    struct sockaddr_in clientaddr, serveraddr;
    int serversock, newserversock, clientsize, n, f, rc;
    char filename[100], filedata[300];
    fflush(stdin);
    serversock = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = 2000;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bind(serversock, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    sizeof(serveraddr);
    listen(serversock, 5);
    while (1)
    {
        clientsize = sizeof(clientaddr);
        newserversock = accept(serversock, (struct sockaddr *)&clientaddr, &clientsize);
        n = read(newserversock, filename, 100);
        filename[n] = 0;
        printf("\nThe requested file from the client is %s.\n", filename);
        f = open(filename, O_RDWR);
        n = read(f, filedata, 300);
        printf("\nThe contents of the file: \n\n");
        printf("%s", filedata);
        write(newserversock, filedata, n);
    }
    close(serversock);
    close(newserversock);
}