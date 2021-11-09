
#include <stdio.h>
int main(void)
{
    printf("i am running\n");
    while (1)
    {
        printf("i am sleeping\n");
        sleep(100); // 睡眠100秒
    }
    return 0;
}