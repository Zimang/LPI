#include<stdio.h>
// open: Acutally I can't use open but fopen
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
int main(int argc, char const *argv[]) {
  FILE *fp,*fo;
  fp=fopen("demo.txt","r");
  fo=fopen("demo2.txt","w");
  int c;
  while ((c=getc(fp))!=EOF) {
    // printf("%c",c);
    putc(c,fo);
  }

/*  if((create("demo3.txt","w"))==-1){
    printf("create file failed\n");
    return -1;
  }
*/
  // int fd1=open("demo3.txt",O_RDWR);
  return 1;
}
