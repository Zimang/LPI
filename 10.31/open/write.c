#include<stdio.h>
#include<fcntl.h>
//#include<unistd.h>
#include<string.h>
extern int errno;

//unistd.h provides access to the POSIX operating system API. 
//typically made up largely of system call wrapper functions such as fork, pipe and I/O primitives (read, write, close, etc.). 

//string.h defines one variable type, one macro, and various functions for manipulating arrays of characters.
//like strlen,strcpy
int main(){
	int fd,sz;
	fd=open("foo.txt",O_RDWR|O_CREAT);
	if(fd<0){
		perror("open");
		exit(1);
	}
	printf("open the fd\n");
	sz=write(fd,"hello geeks\n",strlen("hello geeks\n"));
	printf("called write(%d,\"hello geeks\\n\",%d)."
		"It returns %d\n",fd,strlen("hello geeks\n"),sz);
	if(close(fd)==-1){
		perror("close");
		exit(1);
	}
	printf("close the fd\nLet me introduce another write\n");
	
	int fd_other[2];
	char buf1[30]="I'm huangziming";
	char buf2[30];

	fd_other[0]=open("foobar.txt",O_RDWR|O_CREAT);
	fd_other[1]=open("foobar.txt",O_RDONLY);

	write(fd_other[0],buf1,strlen("I'm huangziming"));
	
	write(1,buf2,read(fd_other[1],buf2,30));
	close(fd_other[0]);
	close(fd_other[1]);
	return 0;
}
