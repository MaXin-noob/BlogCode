#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

//自定义结构体
typedef struct
{
    int a;
    int b;
} exit_t;

void *tfn(void *arg)
{
    exit_t *ret;
    //申请空间
    ret = malloc(sizeof(exit_t)); 
    //赋值
    ret->a = 100;
    ret->b = 300;

    sleep(3);
    return (void *)ret;
}

int main(void)
{
    pthread_t tid;
    exit_t *retval;

    pthread_create(&tid, NULL, tfn, NULL);
    //阻塞等待线程线程结束
    pthread_join(tid, (void **)&retval); 
    //打印返回值
    printf("a = %d, b = %d \n", retval->a, retval->b);
    return 0;
}
