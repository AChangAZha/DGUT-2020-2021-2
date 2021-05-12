#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enterStr(char *str, int num) //输入字符串
{
    int i = 0;
    char tmp[10];
    while (1)
    {
        if ((tmp[i] = getchar()) == '\n' || i >= num - 1)
            break;
        i++;
    }
    tmp[i] = '\0';
    strcpy(str, tmp);
}

int main()
{
    char str[5];
    enterStr(str, 5);
    printf("%s", str);
}