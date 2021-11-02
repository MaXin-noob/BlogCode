#include "stdio.h"

int main(int argc, char *argv[])
{
    FILE *fp; //指定流指针
    if (NULL == (fp = fopen("a.txt", "r")))
    {
        perror(" fail to open");
        return -1;
    }
    fclose(fp);
}