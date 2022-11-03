#include<stdio.h>
#include<fcntl.h>
extern int errno;
int main(){
	int fd;
	fd=open("foo.txt",O_RDWR|O_CREAT);
	if(fd<0){
		perror("open");
		exit(1);
	}
	printf("open the fd");
	if(close(fd)==-1){
		perror("close");
		exit(1);
	}
	printf("close the fd");
}
