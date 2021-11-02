#include <stdio.h>

int main(int argc, char *argv[])
{
    int c;
    while (1) //循环
    {
        c = fgetc(stdin);            // 从键盘读取一个字符
        if (('0' < c) && ('9' >= c)) // 字符判断是否为数字
        {
            fputc(c, stdout); // 满足标准输出
        }
        else if ('\n' == c) // 当遇到‘\n’时跳出
        {
            break;
        }
    }
    return 0;
}