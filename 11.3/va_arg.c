#include<stdio.h>
#include<stdarg.h>

int sum(int, ...);

int main(void){
	//10+20+30
	 printf("\n%d\n",sum(3,10,20,30));
	//10+30+40+100
	 printf("\n%d\n",sum(4,10,30,40,100));
	return 0;	
		
}
int sum(int num_args,...){
	int val=0,i, temp=0;
	va_list ap;

	va_start(ap,num_args);
	for(i=0;i<num_args;i++){
		temp=va_arg(ap,int);
		val+=temp;
		printf("%d ",temp);
	}
	va_end(ap);
	return val;
}
