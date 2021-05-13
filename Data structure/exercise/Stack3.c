/* 计算后缀算术表达式 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef int DataType;
#define A "42/82/342/-*2*+"
#include "LinStack.h"
int PostExp(char str[])
{
    int x, x1, x2, i;
    LSNode *head;
    StackInitiate(&head);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (isdigit(str[i]))
        {
            x = (int)(str[i] - 48);
            StackPush(head, x);
        }
        else
        {
            StackPop(head, &x2);
            StackPop(head, &x1);
            switch (str[i])
            {
            case '+':
            {
                x1 += x2;
                break;
            }
            case '-':
            {
                x1 -= x2;
                break;
            }
            case '*':
            {
                x1 *= x2;
                break;
            }
            case '/':
            {
                if (x2 == 0.0)
                {
                    printf("除数为0错！\n");
                    Destroy(head);
                    exit(0);
                }
                else
                {
                    x1 /= x2;
                }
            }
            }
            StackPush(head, x1);
        }
    }
    StackPop(head, &x);
    Destroy(head);
    return x;
}
int main()
{
    char str[] = A;
    printf("结果为%d", PostExp(str));
    return 0;
}