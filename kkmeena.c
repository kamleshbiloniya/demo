#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
    int fd[2];
    pipe(fd);

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        dup2(fd[0], 0);
        close(fd[1]);
        execlp("wc", "wc","-l", NULL);
        perror("Error from parent::");
        exit(1);
    } else {

        dup2(fd[1], 1);
        close(fd[0]);
        execlp("grep", "grep","-rF", "kanpur", "kkmeena", NULL);
        perror("Error from child::");
        exit(1);
    }

    return 0;
}