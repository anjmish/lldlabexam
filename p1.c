
#include<stdio.h>
#include<sys/types.h>
int main()
{
int filedesc;
char Ubuff="user buffer to kernel buffer"
char Kbuff[100];
filedesc=open("/dev/mychardevice",O_RDWR,0777);
if(filedesc<0)
{
printf("error");
exit(1);
}
write(filedesc,Ubuff,sizeof(Ubuff);
printf("data read from kernel is",Kbuff);
close(filedesc);
}
