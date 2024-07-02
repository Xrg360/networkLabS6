#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

void main(){
    int sockd;
    struct sockaddr_in server,client;
    char server_msg[200],client_msg[200];
    int client_len = sizeof(client);
    int server_len = sizeof(server);

    memset(server_msg,'\0', sizeof(server_msg));
    memset(client_msg,'\0', sizeof(client_msg));

    sockd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);

    server.sin_family= AF_INET;
    server.sin_port = htons(2000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(sockd,"hello there from clinet",strlen("hello there from clinet"),0,(struct sockaddr *)&server,server_len);

}