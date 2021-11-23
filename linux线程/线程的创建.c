#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *fun(void *arg)
{
    printf("I'm thread, Thread ID = %lu\n", pthread_self());
    return NULL;
}

int main(void)
{
    pthread_t tid;

    pthread_create(&tid, NULL, fun, NULL);
    sleep(1); 
    //父线程退出时，子线程均会强制退出
    printf("I am main, my pid = %d\n", getpid());

    return 0;
}