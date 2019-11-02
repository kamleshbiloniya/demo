#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>  
#include <stdlib.h> 
#include <errno.h>   
#include <sys/wait.h> 
int main(){
	int pid;
	pid = fork();
	if (pid > 0){
	 pid = wait(&pid);
	} else{
	printf("chid's PID:%d\n",(int)getpid());
	 execlp("ls", "", NULL);
	 exit(0);
	}
	printf("pid:%d\n",(int)getpid());
	return 0;

}