#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<time.h>
#include<sys/time.h>
#include<netinet/in.h>  
#include<unistd.h>
#include<netdb.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

struct timeval timeout;

void func(int connfd){
    char buff[MAX];
    int flag[20]= {0};
    int f,c,ack,next=0,w1=1,w2,ws,nacksend=0;
    printf("Enter the window size of the server: ");
    scanf("%d",&ws);
    w2=ws-1;
    while (1)
    {
        sleep(1);
        memset(buff,0,MAX);
        recv(connfd,buff,MAX,0);
        if (strcmp("Exit",buff)==0)
        {
            printf("Exit\n");
            break;
        }
        f=atoi(buff);
        c = rand()%2;
        switch (c)
        {
        case 0:
            continue;
            break;
        case 1: sleep(2);
            break;
        
        default:
            break;
        }

        if (f>=w1 && flag[f]==0)
        {
            if (f==w1)
            {
                nacksend =0 ;
                flag[f]=1;
                for(;w1<=w2 && flag[w1]==1;w1++);
                printf("Frame %d received ackknowledgement sent for %d\n",f,w1-1);
                bzero(buff,sizeof(buff));
                snprintf(buff,sizeof(buff),"%d",w1-1);
                send(connfd,buff,sizeof(buff),0);
                w2 = w1+ws;
            }
            else{
                if (nacksend == 0)
                {
                    printf("Frame %d received instead of %d\n sending NAK %d",f,w1,-1*w1);
                    bzero(buff,sizeof(buff));
                    snprintf(buff,sizeof(buff),"%d",-1*w1);
                    send(connfd,buff,sizeof(buff),0);
                    nacksend = 1;
                    flag[f]=1;
                }
                else{
                    printf("Frame %d received instead of %d\n",f,w1);
                    flag[f]=1;
                    continue;
                }
                
            }
            
        }
        // else
        //     printf("Frame %d discarded\n",f);
        

    }
    

}

void main(){
    int sockfd,connfd,len;
    struct sockaddr_in serveraddr,client;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        printf("Socket creation failed\n");
        exit(0);
    }
    else
        printf("Socket created\n");

    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(PORT);

    if(bind(sockfd,(SA*)&serveraddr,sizeof(serveraddr))<0){
        perror("Bind failed. Error");
        return;
    }
    printf("Bind done\n");

    listen(sockfd,5);
    printf("Server listening .. \n");

    len = sizeof(client);
    connfd = accept(sockfd,(SA*)&client,&len);

    if (connfd<0)
    {
        printf("Server acccept failed\n");
        exit(0);
    }
    else
    {
        printf("Server acccept the client\n");
    }
    
    printf("accepted");
    func(connfd);
    close(sockfd);
    
}