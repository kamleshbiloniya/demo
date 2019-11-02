#include<stdio.h>
void fun(){
	int src = 1;
	int dst;   

	asm volatile ("mov %1, %0;"
	    "add $1, %0"
	    : "=r" (dst) 
	    : "r" (src)
		: "memory"
		);
	printf("%d\n", dst);

}
int main(){
	fun();
	return 0;
}