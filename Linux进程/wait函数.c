#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    pid_t pid, wpid;
    int status;
    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("I am child,my parent pid = %d\ngoing to sleep 3s\n", getppid());
        sleep(3);
        printf("-------------child die------------------\n");
        return 0;
    }
    else
    {
        // 回收子进程，避免出现僵尸进程,注意这里是阻塞运行，也就是父进程会一直等到子进程结束
        wpid = wait(&status);

        if (wpid == -1)
        {
            perror("wait error:");
            exit(1);
        }

        // 正常退出
        if (WIFEXITED(status))
        {
            printf("child exit normal,return: %d\n", WEXITSTATUS(status));
        }

        // 异常退出
        if (WIFSIGNALED(status))
        {
            printf("child exit error,return: %d\n", WTERMSIG(status));
        }
        while (1)
        {
            printf("I am parent,my pid = %d,my son = %d\n", getpid(), pid);
            sleep(1);
        }
    }
    return 0;
}
