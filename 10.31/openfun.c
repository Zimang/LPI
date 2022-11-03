// C program to illustrate
// open system call
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
// fcntl.h manipulate file descriptor,which means include O_RDONLY,O_CREAT
// O_WRONLY,O_RDWR

// errno.h means system error numbers, ad `extern int errmo` introduced,A value (the error number) is stored in errno by certain library functions when they detect errors. At program startup, the value stored is zero.
 
// C program to illustrate
// open system call
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main()
{	
	// if file does not have in directory
	// then file foo.txt is created.
	int fd = open("foo.txt", O_RDONLY | O_CREAT);
	
	printf("fd = %d/n", fd);
	
	if (fd ==-1)
	{
		// print which type of error have in a code
		printf("Error Number % d\n", errno);
		
		// print program detail "Success or failure"
		perror("Program");				
	}
	
	return 0;
}

