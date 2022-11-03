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
