#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void *tfn(void *arg)
{
    int n = 3;
    while (n--)
    {
        printf("thread count %d\n", n);
        sleep(1);
    }
    return (void *)1;
}

int main(void)
{
    pthread_t tid;
    void *tret;
    long err;

    /*通过线程属性来设置游离态*/
    pthread_attr_t attr; 
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&tid, &attr, tfn, NULL);

    //两种方法都可以
	// pthread_create(&tid, NULL, tfn, NULL);
	// pthread_detach(tid);
    while (1)
    {
        err = pthread_join(tid, &tret);
        printf("thread exit code = %ld\n", (long)tret);
        printf("err= %ld\n", err);
        if (err != 0)
            fprintf(stderr, "thread_join error: %s\n\n", strerror(err));
        else
            fprintf(stderr, "thread exit code %ld\n\n", (long)tret);

        sleep(1);
    }
    return 0;
}