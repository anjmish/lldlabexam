#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
int file;
char Ubuff="user buff sending to kernel";
char Kbuff[100];

file=open("/dev/mydchardevice",O_RDWR,0777);
 if(file<0)
{
printf("error");
exit(1);
}
write(file,Ubuff,sizeof(Ubuff);
printf("data read",Kbuff);
close(file);
}
