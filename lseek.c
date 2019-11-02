#include<stdio.h>
#include <sys/types.h> 
#include <unistd.h>  
#include <stdlib.h> 
#include<fcntl.h> 
#include <errno.h>   
#include <sys/wait.h> 
int main(int argc, char *argv[]) {
int fd = open("file.txt", O_RDONLY);
assert(fd >= 0);
int rc = fork();
if (rc == 0) {
rc = lseek(fd, 10, SEEK_SET);
printf("child: offset %d\n", rc);
} else if (rc > 0) {
(void) wait(NULL);
printf("parent: offset %d\n", (int) lseek(fd, 0, SEEK_CUR));
}
return 0;
}