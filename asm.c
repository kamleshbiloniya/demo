#include<stdio.h>
int sum(int a,int b);	
int main(){
	int op1 = 20;
	int op2 = 30;
	printf("%d + %d = %d \n",op1,op2,sum(op1,op2));
	return 0;
}

ams(
	"_sum:;"
	"pushl %ebp;"
	"movl %esp ,%ebp;"
	"movl 8(%ebp),%eax;"
	"add 12(%ebp),%eax;"
	"movl %ebp ,%esp;"
	"popl %ebp;"
	"ret"
	);