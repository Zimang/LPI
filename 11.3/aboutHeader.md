[TOC]



# Macros

## #ifndef ==>if not defined

The #ifndef preprocessor only checks If the specific macro is not at all defined with the help of the #define directive. If the condition is TRUE then it will be helpful in executing the code otherwise the else code of the #ifndef will be compiled or executed only if present.

### syntax

```c
#ifndef MACRO
//Code Statements
#else
//Code Statements which are used to include if the specific token is defined
#endif
```

### example

Inside of the main() int variable a1 is created with the value “0” and  then #ifndef preprocessor directive is used with the macro definition as INPUT and then a1 variable value is stored with the value “2” and then  #else directive is used in order to get the input from the user. Then  #endif directive of the C language is used to end the $ifndef directive. Then the value of the a1 is printed with the help of the printf()  function. 

```c
#include <conio.h>
#include <stdio.h>
#define INPUT
void main() {
int a1=0;
#ifndef INPUT
a1=2;
#else
printf("Enter a1 value :: ");
scanf("%d", &a1);
#endif
printf("The value of a1 :: %d\n", a1);
}
```

<img src="https://cdn.educba.com/academy/wp-content/uploads/2020/07/ifndef-in-C-Example-1.png.webp" alt="#ifndef in C Example 1" style="zoom:200%;" />

## #if-else-endif

### syntax

```c
#if _condition_
// Statements to be executed when condition returns TRUE
#else
// statements to be executed when condition in #if results to false.
#endif
```

### example



```c
#include <stdio.h>
#define LIMIT 5
int main()
{
int number;
printf("Enter a number : ");
scanf("%d",&number);
#if number < LIMIT
printf("Entered Number is less than the limit \n");
#else
printf("Entered Number is greater than the limit \n");
#endif
return 0;
}
```



![#else in c 1](https://cdn.educba.com/academy/wp-content/uploads/2020/07/else-in-c-1.jpg.webp)



## #ifdef ==> if defined

### syntax

```c
#ifdef MACRO
// code…
#else
//code of else….
#endif
```



### example

```c
#include <stdio.h>
#define AGE 32
int main()
{
//executes if AGE is present
#ifdef AGE
printf("I am %d years old.\n", AGE);
#endif
printf("This is a sample program on #ifdef directive...\n");
return 0;
}
```

![#ifdef in C output 1](https://www.educba.com/academy/wp-content/uploads/2020/07/ifdef-in-C-output-1.png)

## #undef ==>remove defined

When a constant is defined using #define one can limit its scope using #undef directive in a large program.

## #if defined(x) || y : a much readable way

The above statement means "either x is defined or y is true".

# <sys/stat.h>

## mode_t

A mode is created from or’d permission bit masks defined in `<sys/stat.h>`:

```c
#define S_IRWXU 0000700    /* RWX mask for owner */
#define S_IRUSR 0000400    /* R for owner */
#define S_IWUSR 0000200    /* W for owner */
#define S_IXUSR 0000100    /* X for owner */

#define S_IRWXG 0000070    /* RWX mask for group */
#define S_IRGRP 0000040    /* R for group */
#define S_IWGRP 0000020    /* W for group */
#define S_IXGRP 0000010    /* X for group */

#define S_IRWXO 0000007    /* RWX mask for other */
#define S_IROTH 0000004    /* R for other */
#define S_IWOTH 0000002    /* W for other */
#define S_IXOTH 0000001    /* X for other */

#define S_ISUID 0004000    /* set user id on execution */
#define S_ISGID 0002000    /* set group id on execution */
#define S_ISVTX 0001000    /* save swapped text even after use */
```

In other words, a `mode_t` consists of a load of bit-packed booleans. Ignoring the last three, this gives their bit number:



|       | Read?              | Write?             | Execute?           |
| ----- | ------------------ | ------------------ | ------------------ |
| Owner | `S_IRUSR = 1 << 8` | `S_IWUSR = 1 << 7` | `S_IXUSR = 1 << 6` |
| Group | `S_IRGRP = 1 << 5` | `S_IWGRP = 1 << 4` | `S_IXGRP = 1 << 3` |
| Other | `S_IROTH = 1 << 2` | `S_IWOTH = 1 << 1` | `S_IXOTH = 1 << 0` |

Those defined constants are almost as hard to read as the numbers!

Here are some examples, with some functions to manipulate `mode_t` values.

```c
#include <sys/stat.h>
#include <stdbool.h>
#include <stdio.h>

enum class { CLASS_OWNER, CLASS_GROUP, CLASS_OTHER };
enum permission { PERMISSION_READ, PERMISSION_WRITE, PERMISSION_EXECUTE };
const mode_t EMPTY_MODE = 0;
mode_t perm(enum class c, enum permission p) { return 1 << ((3-p) + (2-c)*3); }
bool mode_contains(mode_t mode, enum class c, enum permission p) { return mode & perm(c, p); }
mode_t mode_add(mode_t mode, enum class c, enum permission p) { return mode | perm(c, p); }
mode_t mode_rm(mode_t mode, enum class c, enum permission p) { return mode & ~perm(c, p); }

// buf must have at least 10 bytes
void strmode(mode_t mode, char * buf) {
  const char chars[] = "rwxrwxrwx";
  for (size_t i = 0; i < 9; i++) {
    buf[i] = (mode & (1 << (8-i))) ? chars[i] : '-';
  }
  buf[9] = '\0';
}

int main(void) {
  char buf[10];
  mode_t examples[] = { 0, 0666, 0777, 0700, 0100, 01, 02, 03, 04, 05, 06, 07 };
  size_t num_examples = sizeof(examples) / sizeof(examples[0]);
  for (size_t i = 0; i < num_examples; i++) {
    strmode(examples[i], buf);
    printf("%04o is %s\n", examples[i], buf);
  }
  return 0;
}
```

This prints:

```shell
$ ./a.out
0000 is ---------
0666 is rw-rw-rw-
0777 is rwxrwxrwx
0700 is rwx------
0100 is --x------
0001 is --------x
0002 is -------w-
0003 is -------wx
0004 is ------r--
0005 is ------r-x
0006 is ------rw-
0007 is ------rwx
```



# `<sys/types.h>`

## ssize_t

In short, `ssize_t` is the same as `size_t`, but is a signed type - read `ssize_t` as **“signed `size_t`”**. `ssize_t` is able to represent the number `-1`, which is returned by several system calls and library functions as a way to indicate error. For example, the `read` and `write` system calls:

```c
#include <sys/types.h>
#include <unistd.h>

ssize_t read(int fildes, void *buf, size_t nbyte);
ssize_t write(int fildes, const void *buf, size_t nbyte);
```



#  <stdarg.h>

The **stdarg.h** header defines a variable type **va_list** and  three macros which can be used to get the arguments in a function when  the number of arguments are not known i.e. variable number of arguments.

## va_list

This is a type suitable for holding information needed by the three macros **va_start(), va_arg()** and **va_end()**.

## va_start(),va_arg(),va_end()

| Sr.No. |                     Macro & Description                      |
| ------ | :----------------------------------------------------------: |
| 1      | [void va_start(va_list ap, last_arg)](https://www.tutorialspoint.com/c_standard_library/c_macro_va_start.htm) This macro initializes **ap** variable to be used with the **va_arg** and **va_end** macros. The **last_arg** is the last known fixed argument being passed to the function i.e. the argument before the ellipsis. |
| 2      | [type va_arg(va_list ap, type)](https://www.tutorialspoint.com/c_standard_library/c_macro_va_arg.htm) This macro retrieves the next argument in the parameter list of the function with type **type**. |
| 3      | [void va_end(va_list ap)](https://www.tutorialspoint.com/c_standard_library/c_macro_va_end.htm) This macro allows a function with variable arguments which used the **va_start** macro to return. If **va_end** is not called before returning from the function, the result is undefined. |



### example

```c
#include<stdarg.h>
#include<stdio.h>

int sum(int, ...);

int main(void) {
   printf("Sum of 10, 20 and 30 = %d\n",  sum(3, 10, 20, 30) );
   printf("Sum of 4, 20, 25 and 30 = %d\n",  sum(4, 4, 20, 25, 30) );
   return 0;
}

int sum(int num_args, ...) {
   int val = 0;
   va_list ap;
   int i;

   va_start(ap, num_args);
   for(i = 0; i < num_args; i++) {
      val += va_arg(ap, int);
   }
   va_end(ap);
 
   return val;
}
/*
result:
Sum of 10, 20 and 30 = 60
Sum of 4, 20, 25 and 30 = 79
*/
```

```c
//type const char*

#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
void printChar(const char *format, ...);

int main(void){
	//A B C
	printChar("3","A","B","C");
	//C B A D
	printChar("4","C","B","A","D");
	return 0;	
		
}
void printChar(const char *char_args,...){
	va_list ap;
	va_start(ap,char_args);
	int i;	
	for(i=0;i<atoi(char_args);i++)
		printf("%s ",va_arg(ap,const char*));
	va_end(ap);
	printf("\n");
}
//result
/*
A B C 
C B A D 
*/

```





# <stdio.h>

## setvbuf()

 **int setvbuf(FILE \*stream, char \*buffer, int mode, size_t size)** defines how a stream should be buffered.

### Parameters

- **stream** − This is the pointer to a FILE object that identifies an open stream.
- **buffer** − This is the user allocated buffer. If set to NULL, the function automatically allocates a buffer of the specified size.
- **mode** − This specifies a mode for file buffering −

| Sr.No. |                      Mode & Description                      |
| ------ | :----------------------------------------------------------: |
| 1      | **_IOFBF**  **Full buffering** − On output, data is written once the buffer is full. On Input the buffer is filled when an input operation is  requested and the buffer is empty. |
| 2      | **_IOLBF**  **Line buffering** − On output, data is written when a newline  character is inserted into the stream or when the buffer is full, what  so ever happens first. On Input, the buffer is filled till the next  newline character when an input operation is requested and buffer is  empty. |
| 3      | **_IONBF**  **No buffering** − No buffer is used. Each I/O operation is written as soon as possible. The buffer and size parameters are ignored. |

- **size** − This is the buffer size in bytes





## fflush()

The C library function **int fflush(FILE \*stream)** flushes the output buffer of a stream.

### Declaration

Following is the declaration for fflush() function.

```
int fflush(FILE *stream)
```

### Parameters

- **stream** − This is the pointer to a FILE object that specifies a buffered stream.

### Example

```c
#include <stdio.h>
#include <string.h>

int main () {

   char buff[1024];
   
   memset( buff, '\0', sizeof( buff ));
   
   fprintf(stdout, "Going to set full buffering on\n");
   setvbuf(stdout, buff, _IOFBF, 1024);

   fprintf(stdout, "This is tutorialspoint.com\n");
   fprintf(stdout, "This output will go into buff\n");
    
   sleep(5);
    
   fflush( stdout );

   fprintf(stdout, "and this will appear when programm\n");
   fprintf(stdout, "will come after sleeping 5 seconds\n");
   
   sleep(5);
   
   return(0);
}

/*
Going to set full buffering on
This is tutorialspoint.com
This output will go into buff
and this will appear when programm
will come after sleeping 5 seconds
*/
```



## fprintf()



