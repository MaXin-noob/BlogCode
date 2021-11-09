#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    execlp("ls", "ls", "-l", NULL);
    perror("execl");
    exit(1);
}