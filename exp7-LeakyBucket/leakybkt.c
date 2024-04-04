#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define No_of_Packets 10
int randm(int a)
	{
		int rn =(random() % 10) % a;
		return rn == 0 ? 1 : rn;
	}
int main()
	{
		int psize[No_of_Packets],i,clk,bsize,oprate,p_sz_rm=0,p_sz,p_time,op;
		for(i=0;i<No_of_Packets;++i)
			psize[i]=randm(6) *10;
		for(i=0;i<No_of_Packets;++i)
			printf("\nPacket[%d]:%d bytes\t",i,psize[i]);
		printf("\nEnter the output rate:");
		scanf("%d",&oprate);
		printf("\nEnter the bucket size:");
		scanf("%d",&bsize);
		for(i=0;i<No_of_Packets;++i)
			{
				if(psize[i]+p_sz_rm>bsize)
					if(psize[i]>bsize)
						printf("\nIncoming Packet size (%d bytes) is greater than bucket capcity(%d bytes) - Packet Rejected",psize[i],bsize);
					else
						printf("\nBucket capacity exceeded - Packet Rejected");
				else
					{
						p_sz_rm+=psize[i];
						printf("\nIncoming packet size: %d",psize[i]);
						printf("\nBytes remaining to Transmit: %d",p_sz_rm);
						p_time=randm(4) * 10;
						printf("\nTime left for transmission: %d units",p_time);
						for(clk=10;clk<=p_time;clk+=10)
							{
								sleep(1);
								if(p_sz_rm)
									{
										if(p_sz_rm<=oprate)
											op=p_sz_rm,p_sz_rm=0;
										else
											op = oprate, p_sz_rm -= oprate;
										printf("\nPacket of size %d Transmitted",op);
										printf("\n%d bytes remaining to transmit",p_sz_rm);
									}
								else
									{
										printf("\nTime left for transmission: %d units", p_time-clk);
										printf("\nNo packets to transmit");		
									}
							}
					}
			}
	}
						

					
						 
			
