#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc,char *argv[])
{
 int fd;
 int n_char=0;
 char buffer[10];
 fd =open(argv[1],O_RDONLY);
 if(fd==-1)
 {
  printf("File open error\n");
  exit(1);
 }
 while((n_char=read(fd,buffer,1))!=0)
	n_char=write(1,buffer,n_char);
 close(fd);
 return 0;
}
