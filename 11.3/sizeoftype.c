#include<stdio.h>
#include<sys/stat.h>
int main(){
	printf("char:%d\n",sizeof(char));
	printf("int:%d\n",sizeof(int));
//`	printf("enum:%d\n",sizeof(enum{Fuck,nFuck}));
	printf("float:%d\n",sizeof(float));
	printf("long:%d\n",sizeof(long));
	printf("double:%d\n",sizeof(double));
	printf("mode_t:%d\n",sizeof(mode_t));
	printf("ssize_t:%d\n",sizeof(ssize_t));
	printf("size_t:%d\n",sizeof(size_t));
	return 1;
}
