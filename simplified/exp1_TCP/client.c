#include<stdio.h>
#include<string.h>

#include<sys/socket.h>
#include<arpa/inet.h>

void main(){
    struct sockaddr_in server,client;
    int sockd, client_sock,client_size;
    char server_msg[200],client_msg[200];

    memset(server_msg,'\0',sizeof(server_msg));
    memset(client_msg,'\0',sizeof(client_msg));

    sockd = socket(AF_INET,SOCK_STREAM,0);
    
    server.sin_family = AF_INET;
    server.sin_port = htons(2000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockd,(struct sockaddr * )&server,sizeof(server));
    int number_to_send = 900;
    sprintf(client_msg, "%d", number_to_send);

    // Send the number
    send(sockd, client_msg, strlen(client_msg), 0);
}