#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp; //指定流指针
    if (NULL == (fp = fopen("AA.txt", "r")))
    {
        printf(" fail to fopen: %s\n", strerror(errno));
        return -1;
    }

    fclose(fp);
    return 0;
}