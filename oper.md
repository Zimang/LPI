

# vim oper

## oper when insert (only once)



## find word and jump

```shell
:/[word you search]
n
```

## jump to the specific line

```sh
:line number
```

## copy,paste,delete

`yy` or `Y` to copy the line (mnemonic: yank) 
or 
`dd` to `delete` the line (Vim copies what you deleted into a clipboard-like "register", like a *cut* operation)

then

`p` to `paste` the copied or deleted text **after** the current line 
or 
`P` to `paste` the copied or deleted text **before** the current line

## next line

- `o` : next newline and insert

- `j`: next line

- `$`: puts you to the end of the line which means exactlly move up and down

  



# open with close

```c
//Syntax in C language 
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  
int open (const char* Path, int flags [, int mode ]); 
```

## Parameters

### Path

path to file which you want to use 

- Use absolute path begin with “/”, when you are not work in same directory of file.
- Use relative path which is only file name with extension, when you are work in same directory of file.

### flags 

How you like to use

1. O_RDONLY: read only,
2. O_WRONLY: write only
3.  O_RDWR: read and write,
4. O_CREAT: create file if it doesn’t exist
5.  O_EXCL: prevent creation if it already exists

```c
// C program to illustrate close system Call
#include<stdio.h>
#include <fcntl.h>
int main()
{
	int fd1 = open("foo.txt", O_RDONLY);
	if (fd1 < 0)
	{
		perror("c1");
		exit(1);
	}
	printf("opened the fd = % d\n", fd1);
	
	// Using close system Call
	if (close(fd1) < 0)
	{
		perror("c1");
		exit(1);
	}
	printf("closed the fd.\n");
}

```



# read

```c
size_t read (int fd, void* buf, size_t cnt);  
```

**Parameters:**

- **fd:** file descriptor
- **buf:** buffer to read data from
- **cnt:** length of buffer

**Returns: How many bytes were actually read**

- return Number of bytes read on success
- return 0 on reaching end of file
- return -1 on error
- return -1 on signal interrupt

**Important points**

- **buf** needs to point to a valid memory location with length not smaller than the specified size because of overflow.
- **fd** should be a valid file descriptor returned from open() to perform read  operation because if fd is NULL then read should generate error.
- **cnt** is the requested number of bytes read, while the return value is the  actual number of bytes read. Also, some times read system call should  read less bytes than cnt.

```c
// C program to illustrate
// read system Call
#include<stdio.h>
#include <fcntl.h>
int main()
{
int fd, sz;
char *c = (char *) calloc(100, sizeof(char));

fd = open("foo.txt", O_RDONLY);
if (fd < 0) { perror("r1"); exit(1); }

sz = read(fd, c, 10);
printf("called read(% d, c, 10). returned that"
		" %d bytes were read.\n", fd, sz);
c[sz] = '\0';
printf("Those bytes are as follows: % s\n", c);
}

```

# write

```c
#include <fcntl.h>
size_t write (int fd, void* buf, size_t cnt); 
```

**Parameters:**

- **fd:** file descriptor
- **buf:** buffer to write data to
- **cnt:** length of buffer

**Returns: How many bytes were actually written**

- return Number of bytes written on success
- return 0 on reaching end of file
- return -1 on error
- return -1 on signal interrupt

**Important points**

- The file needs to be opened for write operations
- **buf** needs to be at least as long as specified by cnt because if buf size less  than the cnt then buf will lead to the overflow condition.
- **cnt** is the requested number of bytes to write, while the return value is the actual number of bytes written. This happens when **fd** have a less number of bytes to write than cnt.
- If write() is interrupted by a signal, the effect is one of the following:
  -If write() has not written any data yet, it returns -1 and sets errno to EINTR.
  -If write() has successfully written some data, it returns the number of bytes it wrote before it was interrupted.

```c
// C program to illustrate
// write system Call
#include<stdio.h>
#include <fcntl.h>
main()
{
int sz;

int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (fd < 0)
{
	perror("r1");
	exit(1);
}

sz = write(fd, "hello geeks\n", strlen("hello geeks\n"));

printf("called write(% d, \"hello geeks\\n\", %d)."
	" It returned %d\n", fd, strlen("hello geeks\n"), sz);

close(fd);
}

// C program to illustrate 
// I/O system Calls 
#include<stdio.h> 
#include<string.h> 
#include<unistd.h> 
#include<fcntl.h> 
  
int main (void) 
{ 
    int fd[2]; 
    char buf1[12] = "hello world"; 
    char buf2[12]; 
  
    // assume foobar.txt is already created 
    fd[0] = open("foobar.txt", O_RDWR);         
    fd[1] = open("foobar.txt", O_RDWR); 
      
    write(fd[0], buf1, strlen(buf1));         
    write(1, buf2, read(fd[1], buf2, 12)); 
  
    close(fd[0]); 
    close(fd[1]); 
  
    return 0; 
} 

```



# the differences and similarities between malloc and calloc 

There are two major differences between `malloc` and `calloc` in C programming language: 

1. First, in the number of arguments. The `malloc()` takes a single argument, while `calloc()` takes two. 
2. Second, `malloc()` does not initialize the memory allocated, while `calloc()` initializes the allocated memory to ZERO.  		

## calloc

```c
/* Allocating memory for an array of 10 elements of type int. */
int *ptr = (int*) calloc(10 ,sizeof (int));
if (ptr == NULL) 
{
  printf("Could not allocate memory\n");
  exit(-1);
} 
else
  printf("Memory allocated successfully.\n")
```
