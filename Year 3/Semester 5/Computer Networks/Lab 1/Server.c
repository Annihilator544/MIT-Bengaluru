#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
int main()
{
int sd;
char buf[25];
struct sockaddr_in sadd,cadd;
//Create a UDP socket
sd=socket(AF_INET,SOCK_DGRAM,0);
//Construct the address for use with sendto/recvfrom... */
sadd.sin_family=AF_INET;
sadd.sin_addr.s_addr=inet_addr("10.19.15.141");//**
sadd.sin_port=htons(9704);
int result=bind(sd,(struct sockaddr *)&sadd,sizeof(sadd));
int len=sizeof(cadd);
while(1)
{
int m=recvfrom(sd,buf,sizeof(buf),0,(struct sockaddr *)&cadd,&len);
printf("the message recieved from client\n");
puts(buf);
printf("enter message to be sent to client\n");
gets(buf);
int n=sendto(sd,buf,sizeof(buf),0,(struct sockaddr *)&cadd,len);
}
return 0;
}