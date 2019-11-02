#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int rc = fork();
	if(rc==0){
		printf("I am child process (pid: %d)\n", getpid());
		rc = fork();
	}
	if (rc!=0){
		printf("I am parent of %d (pid: %d)\n", rc, getpid());
		wait(NULL);
	}
	return 0;
}