
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
main()
{
char buf[8];
	int fd, dfd,fd2;
	fd = open("some.txt", O_RDWR);
	if(fd < 0){
		perror("open");
		exit(-1);
	}
	read(fd,buf,1024);
	close(fd);
}