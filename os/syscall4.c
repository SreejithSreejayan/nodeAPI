#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>

void main(int argc,char **argv)
{
 if(argc!=2)
	printf("Usage error:Invalid number of arguments\n");
 struct stat fs;
 if(stat(argv[1],&fs)<0)
	printf("Usage error:File/dir not found\n");
 printf("Information of %s\n",argv[1]);
 printf("File size:\t\t%d bytes\n",fs.st_size);
 printf("file inode:\t\t%d\n",fs.st_ino);
 printf("File mode:\t\t%d\n",fs.st_mode);
 printf("user ID of file owner:\t%d\n",fs.st_uid);
 printf("File last access time:\t%d\n",fs.st_atime);
}
