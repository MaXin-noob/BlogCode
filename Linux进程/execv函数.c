#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    char *argv[] = {"ls", "-l", NULL};
    execv("/bin/ls", argv);
    perror("execl");
    exit(1);
}