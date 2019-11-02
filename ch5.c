#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>  
#include <stdlib.h> 
#include <errno.h>   
#include <sys/wait.h> 
int add (int a,int b){
	int var;
	int pid = fork();
	printf("pid:%d\n",pid);
	printf("add:%x\n",&var);
	execv('hello');
	return a+b;
}

int main(int argc, char *argv[]) {
printf("hello world (pid:%d)\n", (int) getpid());
// int rc = fork();
// int p = fork();
// if (rc < 0) {
// // fork failed; exit
// fprintf(stderr, "fork failed\n");
// exit(1);
// } else if (rc == 0) { // child (new process)
// printf("hello, I am child (pid:%d)\n", (int) getpid());
// } else {
// // parent goes down this path (main)
// printf("hello, I am parent of %d (pid:%d)\n",
// rc, (int) getpid());
// }
// printf("%d\n",p);
add(3,2);
printf("My pid is :%d\n",(int)getpid());
int b ;
scanf("%d",&b);
printf("%d\n",b );
return 0;
}