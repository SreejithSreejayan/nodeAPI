#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
 pid_t pid;
 int cstatus;
 pid_t c;
 pid=fork();
 if(pid==-1)
	printf("Error in creating process\n");
 else if(pid==0)
	{
	 printf("Executing in child process\n");
	 execvp(argv[1],&argv[1]);
	 perror("exec failure\n");
	 exit(1);
	}
 else
 {
  printf("Executing in parent process\n");
  c=wait(&cstatus);
  printf("parent:child %ld exited with status= %d\n",(long)c,cstatus);
 }
}
