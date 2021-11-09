#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();

    if (pid == 0)
    { // 子进程一直执行,即死循环
        while (1)
        {
            printf("I am a child, pid=%d, ppid=%d\n", getpid(), getppid());
            sleep(1);
        }
    }
    else
    {
        int count = 2; // 父进程执行2次
        while (count--)
        {
            printf("I am a father, pid=%d, ppid=%d\n", getpid(), getppid());
            sleep(1);
        }
        //执行2次之后退出
        exit(1);
    }

    return 0;
}
