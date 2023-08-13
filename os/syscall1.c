#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

void main()
{
 pid_t pid;
 pid=fork();
 if(pid==-1)
	printf("Error in creating process\n");
 else if(pid==0)
	{
	 printf("Executing in child process\n");
	 printf("Child process pid= %d\n",getpid());
	 printf("Parent process pid= %d\n",getppid());
	}
 else
	printf("Executing in parent process, pid= %d\n",getppid());
}
