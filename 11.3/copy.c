#include<sys/stat.h>
//<sys/stat.h> is the header in the C POSIX library for the C programming language that contains constructs that facilitate getting information about files attributes. 
#include<fcntl.h>
#include<tlpi_hdr.h>

#ifndef BUF_SIZE /* Allow "cc -D"  */
#define BUF_SIZE 1024
#endif

int
main(int argc,char *argv){
	int inputFd,outputFd,openFlags;
	mode_t filePerms;
	ssize_t numRead;
	char buf[BUF_SIZE];
	
	if(argc!= 3|| strcmp(argv[1],"--help")==0)
		usageErr("%s old-file new-file\n",argv[0]);
	
	/*Open input and output files */
	inputFd = open(arg[1],O_RDONLY);
	if(inputFd<0)
		errExit
}

