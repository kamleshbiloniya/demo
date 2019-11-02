#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>  
#include <stdlib.h> 
#include <errno.h>   
#include <sys/wait.h> 
int main(){
	int i=0, pid;
	pid = fork();
	if (pid > 0){
			sleep(1);
			printf("parent : %d\n", i);
			wait(&pid);
	} 
	else{
		i = i + 1;
		printf("child : %d\n", i);
	}

	return 0;
}
