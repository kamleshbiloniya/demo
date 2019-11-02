#include<stdio.h>
#include <sys/types.h> 
#include <unistd.h>  
#include <stdlib.h> 
#include <errno.h>   
#include <sys/wait.h> 
int main(int argc, char const *argv[])
{
	int pid = fork();
	// int pid  = 2;
	// char * argv_list[] = {"ls","-lart","/home",NULL};
	// wait(&pid);
	if(pid ==0){
		printf("from child hiii\n");
		printf("hello world %d \n",pid);
	}
	else{
		unsigned long k = -5;
		printf("hello world k= %ul \n",k);
	}
	
	return 0;
}