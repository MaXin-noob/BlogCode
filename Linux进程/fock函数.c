#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("error");
    }
    if (pid == 0)
    {
        printf("i am a child process\n"); 
    }
    else
    {
        printf("i am a father process\n"); 
    }
    return 0;
}
