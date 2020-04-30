#include<stdio.h>
int main(){
	int i=0, pid;
	pid = fork();
	if (pid > 0){
		sleep(1);
		i += 1;
		printf("parent : %d\n", i);
		wait();
	} else{
		i = i + 1;
		printf("child : %d\n", i);
	}
	return 0;
}