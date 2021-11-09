#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        int count = 2; // 子进程运行2次
        while (count--)
        {
            printf("I am a child, pid=%d, ppid=%d\n", getpid(), getppid());
            sleep(1);
        }
        exit(0);
    }
    else
    { // 父进程一直运行
        while (1)
        {
            printf("I am a father, pid=%d, ppid=%d\n", getpid(), getppid());
            sleep(1);
        }
    }
    return 0;
}
