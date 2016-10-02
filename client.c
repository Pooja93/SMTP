#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
int main(int argc,char *argv[])
{
int create_socket,cont;
int bufsize=1024,count=0;
char *buffer=malloc(bufsize);
char fname[256],passk[10],logink[10];
struct log
{
char login[10];
char pass[10]
}logs[10];
int opt,i=0;
struct sockaddr_in address;
 FILE *file_to_send;
    int ch;
    char toSEND[1];
    char remoteFILE[4096];
    int count1=1, count2=1, percent;


if((create_socket=socket(AF_INET,SOCK_STREAM,0))>0)
printf("The socket was created\n");
address.sin_family=AF_INET;
address.sin_addr.s_addr = INADDR_ANY;
address.sin_port=htons(7000);
inet_pton(AF_INET,argv[1],&address.sin_addr);
if(connect(create_socket,(struct sockaddr *)&address,sizeof(address))==0)
printf("The connection was accepted with the server:%s...\n",argv[1]);
while(1)
{
printf("Enter the Command : ");
gets(fname);
fname[strlen(fname)+1] = '\0';
if((strcmp(fname,"DATA")!=0)&&(strcmp(fname,"IMAG")!=0))
{
if(strcmp(fname,"EHLO")==0)
{
printf("\nSize extended:1000");
}
send(create_socket,fname,strlen(fname),0);
         if((cont=recv(create_socket,buffer,bufsize,0))>0) {
write(1,buffer,cont);
memset(buffer,0,1024);
memset(fname,0,256);
}
}
if(strcmp(fname,"IMAG")==0)
{
send(create_socket,fname,strlen(fname),0);
        file_to_send = fopen("1.jpeg", "r");
        if(!file_to_send)
    {
        printf("Error opening file\n");

        continue;
    }
    else
    {
        long fileSIZE;
        fseek(file_to_send,0,SEEK_END);
        fileSIZE=ftell(file_to_send);
        rewind(file_to_send);
         sprintf(remoteFILE,"FBEGIN:%s:%ld\r\n","j.jpeg",fileSIZE);
        send(create_socket,remoteFILE,sizeof(remoteFILE),0);
        percent = fileSIZE/100;
        while((ch=getc(file_to_send))!=EOF)
        {
            toSEND[0]=ch;
            send(create_socket,toSEND,1,0);
      /*    if(count1==count2)
            {
                printf("33[0;0H");
                printf("\33[2J");
                printf("Filename: %s\n","1.jpeg");
                printf("Filesize: %ld Kb\n", fileSIZE/1024);
                printf("Percent: %d%% (%d Kb)\n", count1/percent,count1/1024);
                count1+=percent;
            }*/
          //  count2++;
        }
    }

if((cont=recv(create_socket,buffer,bufsize,0))>0) {
write(1,buffer,cont);
memset(buffer,0,1024);
memset(fname,0,256);
 fclose(file_to_send);
}
}

if(strcmp(fname,"DATA")==0)
{
//printf("enter the command");
char c;
int i=0;
fname[strlen(fname)+1] = '\0';
send(create_socket,fname,strlen(fname),0);
if((cont=recv(create_socket,buffer,bufsize,0))>0) {
write(1,buffer,cont);
memset(buffer,0,1024);
memset(fname,0,256);
}

printf("Enter the Data : ");
while(1)
{
c=getchar();
if(c=='\n')
{
c=getchar();
if(c=='.')
{
c=getchar();
if(c=='\n')
	break;
else
	fname[i++]=c;
}
else
	fname[i++]=c;
}
else
	fname[i++]=c;
}
fname[strlen(fname)+1] = '\0';
send(create_socket,fname,strlen(fname),0);
if((cont=recv(create_socket,buffer,bufsize,0))>0) {
write(1,buffer,cont);
memset(buffer,0,1024);
memset(fname,0,256);
}
}
if(strcmp(fname,"QUIT")==0)
	{
		printf("Quit\n");
		break;
	}
}
           return close(create_socket);
}
