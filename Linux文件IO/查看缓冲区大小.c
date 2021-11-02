#include "stdio.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char a = 'a';
    if (argc != 2)
    {
        printf("Usage:%s Number\n", argv[0]);
        return 0;
    }
    for (int i = 0; i < atoi(argv[1]); i++)
    {
        printf("%c", a);
    }
    while (1)
    {
    }
    return 0;
}