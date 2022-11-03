#include<stdio.h>
#include<fcntl.h>
int main(){
	int fd =open("foo.txt",O_EXCL|O_RDONLY),sz;
	char* buf=(char*)calloc(100,sizeof(char));
	if(fd<0){
		perror("open");
		exit(1);
	}
	sz=read(fd,buf,100);
	buf[sz]='\0';
	printf("as you see\nnothing or\n%s\n",buf);
	if((close(fd))<0){
		perror("close");
		exit(1);
	}
}
