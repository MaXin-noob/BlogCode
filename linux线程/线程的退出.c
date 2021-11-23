#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *fn(void *arg)
{
    long i = 0;
    //强制类型转化
    i = (long)arg;
    //通过i来区别每个线程
    if (i == 2)
        pthread_exit(NULL);
    sleep(i);
    printf("I'm %ldth thread, Thread_ID = %lu\n", i + 1, pthread_self());
    return NULL;
}

int main(int argc, char *argv[])
{
    long n, i;
    pthread_t tid;
    //接受参数
    if (argc == 2)
        n = atoi(argv[1]);
    else
        exit(0);
    //循环创建线程
    for (i = 0; i < n; i++)
    {
        pthread_create(&tid, NULL, fn, (void *)i);
    }

    sleep(n);
    printf("I am main, I'm a thread!\n");
    printf("main_thread_ID = %lu\n", pthread_self());

    return 0;
}
