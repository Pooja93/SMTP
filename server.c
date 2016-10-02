#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<time.h>
int processCommands(char *);
char fromvalid[4][20]={"yahoo.com","google.com","rediff","myntra"};
int status, rcpt_count, data_fd,rcpt_max=3;
char toAddresses[3][256];
char fromAddress[256];
char *buffer;
 char recvBUFF[4096];
  char *filename, *filesize;
   FILE *recvFILE;
   int received = 0;
    char tempstr[4096];
int parseARGS(char **args, char *line)
{
    int tmp = 0;
    args[tmp] = strtok(line, ":" );
    while ((args[++tmp] = strtok(NULL, ":" )) != NULL);
    return tmp -1;
}
int count1=1, count2=1, percent;
char *header[4096];
int cont=0, create_socket, new_socket, addrlen, fd;
int main (int argc,char **argv)
{
         char fname[256];
int bufsize=1024,n;
buffer=malloc(bufsize);
  struct sockaddr_in address;
  if ((create_socket = socket (AF_INET, SOCK_STREAM, 0)) > 0)
    printf ("the socket was created");
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons (7000);
  if (bind (create_socket, (struct sockaddr *) &address, sizeof (address)) == 0)
    printf ("\nbinding socket\n");
  listen (create_socket, 3);
  addrlen = sizeof (struct sockaddr_in);
 new_socket = accept (create_socket, (struct sockaddr *) &address, &addrlen);
  if (new_socket > 0)
    printf ("the client %s is connected..\n", inet_ntoa (address.sin_addr));
while(1)
{
if((n=read(new_socket, fname, 255)) >0) {
if(status!=2)
  printf ("command %s received\n", fname);
if(status==2)
	processDATA(fname,strlen(fname));
else
	{fd = processCommands(fname);
            if(fd==221)
	break;
}
	cont=strlen(buffer);
	buffer[strlen(buffer)+1] = '\0';
	send (new_socket, buffer, cont, 0);

memset(buffer,0,1024);
memset(fname,0,256);
}
}
  printf ("request completed\n");
  close (new_socket);
  return close (create_socket);
}
int processCommands(char *cmd)
{
int len=strlen(cmd);
if(strncmp(cmd,"HELO",4)==0 || strncmp(cmd,"EHLO",4)==0)
	return processHELO(cmd,len);
else if(strncmp(cmd,"MAIL FROM:<",11)==0)
	return processMAIL(cmd,len);
else if(strncmp(cmd,"IMAG",4)==0)
        return processIMAG(cmd,len);
else if(strncmp(cmd,"RCPT",4)==0)
	return processRCPT(cmd,len);
else if(strncmp(cmd,"DATA",4)==0)
	return processDATA(cmd,len);
else if(strncmp(cmd,"RSET",4)==0)
	return processRSET(cmd,len);
else if(strncmp(cmd,"VRFY",4)==0)
	return processVRFY(cmd,len);
else if(strncmp(cmd,"HELP",4)==0)
	return processHELP(cmd,len);
else if(strncmp(cmd,"NOOP",4)==0)
	return processNOOP(cmd,len);
else if(strncmp(cmd,"QUIT",4)==0)
	return processQUIT(cmd,len);
else if (strncmp(cmd,"EXPN",4)==0)
return processEXPN(cmd,len);
        else return 0;
}
        int processEXPN(char *cmd,int len)
{

printf("\nreceived EXPN\n");
rcpt_max=5;
return cmdResponse(252);
}

         int processHELO(char *cmd, int len)
{
printf("\nreceived helo\n");
cmd +=5;
status=1;
memset(fromAddress,0,256);
memset(toAddresses,0,sizeof(toAddresses));
rcpt_count=0;
int processIMAG(char *cmd,int len)
{
 while(1)
    {
        if(recv(new_socket, recvBUFF, sizeof(recvBUFF),0))
        {
            if(!strncmp(recvBUFF,"FBEGIN",6))
            {
            recvBUFF[strlen(recvBUFF)-2] = 0;
            parseARGS(header, recvBUFF);
            filename = header[1];
            filesize = header[2];
            }
        recvBUFF[0] = 0;
        recvFILE = fopen(filename, "w");
     //   percent = atoi(filesize)/100;
      // printf("Current percent value: %d\n",percent);
        while(1)
        {
            if(recv(new_socket,recvBUFF,1,0) != 0)
            {
                fwrite(recvBUFF,sizeof(recvBUFF[0]),1,recvFILE);
          /*     if(count1==count2)
                {
                    printf("33[0;0H");
                    printf("\33[2J");
                    printf("Filename: %s\n", filename);
                    printf("Filesize: %d Kb\n", atoi(filesize)/1024);
                    printf("Percent: %d%% (%d Kb)\n", count1/percent,count1/1024);
                    count1+=percent;
                    printf("Show count1 value: %d\n",count1);
                }
                count2++;
                printf("Show count2 value: %d\n", count2);
                received++;*/
                recvBUFF[0] = 0;
memset(addr,0,231);
         st=strchr(cmd,'<');
en=strchr(cmd,'>');
st++;
alen=en-st;

strncpy(addr,st,alen);

strcpy(fromAddress,addr);

printf("FROM <%s>",fromAddress);

if(!(strlen(addr)>2 && strchr(addr,'@')))
	return cmdResponse(501);

for(i=0;i<3;i++)
{
if((strcmp(fromAddress,fromvalid[i]))==0)
{
f=1;
break;
}
}
if(f==0)
return cmdResponse(590);


else
return cmdResponse(250);

}

int processRCPT(char *cmd,int len)
{

if(status!=1)
	return cmdResponse(503);
if(rcpt_count>=rcpt_max)
	return cmdResponse(552);
char addr[256+11];
char user[64+5];
char domain[64+5];
char userPath[64+64+1+1];
char *st,*en,*dom=domain;
int alen;
printf("\nreceived RCPT\n");

memset(addr,0,231);

st=strchr(cmd,'<');
en=strchr(cmd,'>');
st++;
alen=en-st;
strncpy(addr,st,alen);
dom=strchr(addr,'@');
dom=dom+1;
if(!(strlen(addr)>2 && strchr(addr,'@')))
	return cmdResponse(501);

memset(user,0,sizeof(user));

strncpy(user,addr,strlen(addr)-strlen(dom)-1);

printf("RCPT [%s] user [%s] domain [%s]\n",addr,user,dom);

strcpy(toAddresses[rcpt_count],addr);
printf("recepient %s saved\n",toAddresses[rcpt_count]);
rcpt_count++;

data_fd=open(user,O_RDWR|O_CREAT,0777);
return cmdResponse(250);
}
int processHELP(char *cmd,int len)
{
printf("Received HELP\n");
return cmdResponse(214);
}
int processNOOP(char *cmd,int len)
{
printf("Received NOOP\n");
return cmdResponse(220);
}

int processQUIT(char *cmd,int len)
{
printf("Received QUIT\n");
return cmdResponse(221);
}


int processVRFY(char *cmd,int len)
{
int i;
char userAddr[64+1];
printf("Received VRFY\n");
cmd=cmd+5;
strncpy(userAddr,cmd,len-5);
printf("%s\n",userAddr);
for(i=0;i<3;i++)
	if(strcmp(userAddr,toAddresses[i])==0)
		return cmdResponse(250);

return cmdResponse(252);
}

int processDATA(char *cmd,int len)
{
int p;


char *dataEnd="STOP";

if(status!=2)
{
	status=2;
	return cmdResponse(354);
}

p=write(data_fd,cmd,len);

if(strstr(cmd,dataEnd))
{
	printf("Data end\n");
	status=3;
	return processDataEnd(cmd,len);
}
else
	return cmdResponse(502);

}

int processRSET(char *cmd,int len)
{
printf("Received RSET\n");
close(data_fd);
memset(fromAddress,0,256);
memset(toAddresses,0,sizeof(toAddresses));
status=1;
rcpt_count=0;
return cmdResponse(250);
}


int processDataEnd(char *cmd,int len)
{
printf("In processDataEnd\n");
int msg_fd,p,i;
char *from = "FROM: ";
char *to= "TO: ";
char *msgfile[3] = {"finalMessage1","finalMessage2","finalMessage3"};
char *newline = "\n";
char *date="DATE: ";
time_t rawtime;
struct tm * timeinfo;
time (&rawtime);
timeinfo = localtime (&rawtime);
char *currentdate =  asctime(timeinfo);

for(i=0;i<rcpt_count;i++)
{
msg_fd=open(msgfile[i],O_RDWR|O_CREAT,0777);
if(msg_fd==-1)
	{
	printf("Can't create file\n");
	break;
	}
write(msg_fd,date,strlen(date));
write(msg_fd,currentdate,strlen(currentdate));
write(msg_fd,from,strlen(from));
write(msg_fd,fromAddress,strlen(fromAddress));
write(msg_fd,newline,strlen(newline));
write(msg_fd,to,strlen(to));
write(msg_fd,toAddresses[i],strlen(toAddresses[i]));
write(msg_fd,newline,strlen(newline));
write(msg_fd,cmd,len);
close(msg_fd);
}

return cmdResponse(250);
}



int cmdResponse(int res_no)
{
if(res_no==220)
	strcpy(buffer,"220  Service Ready\n");
else if(res_no==214)
	strcpy(buffer,"214  Get help online\n");
else if(res_no==221)
	strcpy(buffer,"221  Quitting\n");
else if(res_no==250)
	strcpy(buffer,"250   OK\n");
else if(res_no==252)
	strcpy(buffer,"252    Cannot verify user, send anyway\n");
else if(res_no==354)
	strcpy(buffer,"354   Start mail input, end with STOP\n");
else if(res_no==500)
	strcpy(buffer,"500  Syntax error, command not recognized\n");
else if(res_no==501)
	strcpy(buffer,"501 Syntax error, no parameters allowed\n");
else if(res_no==502)
	strcpy(buffer,"502 Command not implemented\n");
else if(res_no==503)
	strcpy(buffer,"503 Bad sequence of commands\n");
else if(res_no==521)
	strcpy(buffer,"521 Machine does not accept mail\n");
else if(res_no==550)
	strcpy(buffer,"550 Mailbox unavailable\n");
else if(res_no==551)
	strcpy(buffer,"551 User not local\n");
else if(res_no==552)
	strcpy(buffer,"552 Exceeded storage allocation\n");
else if(res_no==553)
	strcpy(buffer,"553 Mailbox name not allowed\n");
else if(res_no==554)
	strcpy(buffer,"554 Transaction failed\n");
else if(res_no==590)
        strcpy(buffer,"590 Unavailable mail box\n");
else
	strcpy(buffer,"%d description not defined\n");

return res_no;
}
