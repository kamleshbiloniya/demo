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
	dfd = dup(fd);
	fd2 = open("some.txt", O_RDWR);
	printf("%d %d %d\n",fd,dfd,fd2);
	buf[7] = 0;
	read(fd, buf, 7);
	printf("%s\n", buf);
	read(dfd, buf, 7);
	printf("%s\n", buf);
	read(fd2, buf, 7);
	printf("%s\n", buf);
}