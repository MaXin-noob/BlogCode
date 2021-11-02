#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i;
    fprintf(stdin, "please input a number:");
    fscanf(stdin, "%d", &i);
    fprintf(stdin, "the number is:%d", i);
    return 0;
}
