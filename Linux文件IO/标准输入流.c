#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i;
    printf("please input a number:");
    fscanf(stdin, "%d", &i);
    printf("the number is:%d", i);
    return 0;
}
