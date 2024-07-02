#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

void main(){
    int sockd;
    struct sockaddr_in server,client;
    char server_msg[200],client_msg[200];
    int client_len = sizeof(client);

    memset(server_msg,'\0', sizeof(server_msg));
    memset(client_msg,'\0', sizeof(client_msg));

    sockd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);

    server.sin_family= AF_INET;
    server.sin_port = htons(2000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(sockd,(struct sockaddr*)&server,sizeof(server));
    printf("listening\n\n");

    recvfrom(sockd,client_msg,sizeof(client_msg),0,(struct sockaddr *)&client,&client_len);
    printf("%s\n\n",client_msg);

    send
}