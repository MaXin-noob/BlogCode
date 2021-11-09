#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
int main()
{
    pid_t pid;
    FILE *fp;
    time_t t;
    int i;
    //捕捉错误
    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(-1);
    }
    //父进程退出
    else if (pid > 0)
    {
        exit(0);
    }
    //fock之后，父进程退出，以下代码只有子进程执行
    //创建一个会话
    setsid();
    //重置文件权限掩码
    umask(0);
    //切换工作目录
    chdir("/tmp");
    //关闭所有的文件描述符
    for (i = 0; i < getdtablesize(); i++)
    {
        close(i);
    }
    //创建新的文件
    if ((fp = fopen("time.log", "a")) == NULL)
    {
        perror("fopen");
        exit(-1);
    }
    while (1)
    {
        time(&t);
        fprintf(fp, "%s", ctime(&t));
        fflush(fp);
        sleep(1);
    }
}