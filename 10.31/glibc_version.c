#include<gnu/libc-version.h>
#include<stdio.h>
const char *gnu_get_libc_version(void);
void main(){
  printf("%s\n",gnu_get_libc_version());
}
