#include<netdb.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<time.h>
#include<sys/time.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

struct timeval timeout;

void func(int sockfd,int nf,int ws){
    char buff[MAX];
    int ack,i=0,n,nk,w1=1,w2=ws,j,flag=0;
    if(setsockopt(sockfd,SOL_SOCKET,SO_RCVTIMEO,(const char*)&timeout,sizeof(timeout))<0){
        perror("setsockopt(SO_RCVTIMEO) failed");
    }

    for(i=1;i<=nf && i<=w2;i++){
        bzero(buff,sizeof(buff));
        nk=send(sockfd,buff,sizeof(buff),0);
        printf("Frame %d sent\n",i);
    }

    while(1){
        while (w2-w1!=ws-1 &&w2!=nf)
        {
            w2++;
            bzero(buff,sizeof(buff));
            snprintf(buff,sizeof(buff),"%d",w2);
            nk=send(sockfd,buff,sizeof(buff),0);
            printf("Frame %d sent\n",w2);
        }
        flag=0;
        bzero(buff,sizeof(buff));
        n=recv(sockfd,buff,MAX,0);
        ack=atoi(buff);
        if (n>0)
        {
            if (ack<0)
            {
                printf("Ack not received for %d\nRESENDING ...\n",ack);
                bzero(buff,sizeof(buff));
                snprintf(buff,sizeof(buff),"%d",ack);
                nk=send(sockfd,buff,sizeof(buff),0);
            }
            else if (ack>=nf)
            {
                printf("Ack received %d\nEXIT\n",ack);
                bzero(buff,sizeof(buff));
                strcpy(buff,"EXIT");    
                break;
            }
            else if (ack>=w1 && ack<=w2)
            {
                w1=ack+1;
                printf("Ack received %d\n",ack);

            }
            
            
        }
        else
        {
            printf("Ack not received for %d\nRESENDING ...\n",w1);
            bzero(buff,sizeof(buff));
            snprintf(buff,sizeof(buff),"%d",w1);
            nk=send(sockfd,buff,sizeof(buff),0);
            flag=1;
        }
        
        
    }
}


void main(){
    int sockfd,connfd;
    struct sockaddr_in serveraddr,client;

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        printf("Socket creation failed\n");
        exit(0);
    }
    else
    {
        printf("Socket created\n");
    }
    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr=INADDR_ANY;
    serveraddr.sin_port=htons(PORT);

    timeout.tv_sec=3;
    timeout.tv_usec=0;

    if (connect(sockfd,(SA*)&serveraddr,sizeof(serveraddr))!=0)
    {
        printf("Connection with server failed\n");
        exit(0);
    }
    else
    {
        printf("Connected to server\n");
    }
    printf("Enter the number of frames to be sent\n");
    int nf;
    scanf("%d",&nf);
    printf("Enter the window size\n");
    int ws;
    scanf("%d",&ws);
    func(sockfd,nf,ws);
    close(sockfd);
}