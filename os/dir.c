
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc, char *argv[]) {
	FILE *dp = opendir(".");
	assert(dp != NULL);
	struct dirent *d;
	while ((d = readdir(dp)) != NULL) {
		printf(" %c\n", d->d_name);
	}
	closedir(dp);
	return 0;
}