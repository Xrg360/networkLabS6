#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

void main(){
    struct sockaddr_in server,client;
    int sockd, client_sock,client_size;
    char server_msg[200],client_msg[200];
    int client_num;
    memset(server_msg,'\0',sizeof(server_msg));
    memset(client_msg,'\0',sizeof(client_msg));

    sockd = socket(AF_INET,SOCK_STREAM,0);
    
    server.sin_family = AF_INET;
    server.sin_port = htons(2000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");


    bind(sockd,(struct sockaddr * )&server,sizeof(server));

    listen(sockd,1);
    printf("listening\n\n");

    client_size = sizeof(client);
    client_sock = accept(sockd,(struct sockaddr * )&client,&client_size );

    recv(client_sock,client_msg,sizeof(client_msg),0);

    printf("%s\n\n",client_msg);
    sscanf(client_msg , "%d",&client_num);
    printf("%d",client_num+2);
    
    send(client_sock,"hello",strlen("hello"),0);

}