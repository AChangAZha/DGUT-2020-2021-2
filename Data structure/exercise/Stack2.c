/* 中缀算术表达式转换成后缀算术表达式 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define A "4/2+((8/2)*(3-4/2))*2";
typedef char DataType;
#include "LinStack.h"
int Transform(char str[], char **a)
{
    int n = strlen(str), i;
    char *p, x, top;
    *a = (char *)calloc(n, sizeof(char));
    LSNode *head;
    StackInitiate(&head);
    StackPush(head, '#');
    p = *a;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (isdigit(str[i]))
        {
            *p = str[i];
            p++;
        }
        else if (str[i] == '+' || str[i] == '-')
        {
            StackTop(head, &top);
            while (top != '(' && top != '#')
            {
                StackPop(head, &x);
                *p = x;
                p++;
                StackTop(head, &top);
            }
            StackPush(head, str[i]);
        }
        else if (str[i] == '*' || str[i] == '/')
        {
            StackTop(head, &top);
            while (top == '*' || top == '/' || top == ')')
            {
                StackPop(head, &x);
                *p = x;
                p++;
                StackTop(head, &top);
            }
            StackPush(head, str[i]);
        }
        else if (str[i] == '(')
        {
            StackTop(head, &top);
            if (top == ')')
            {
                Destroy(head);
                return 0;
            }
            StackPush(head, str[i]);
        }
        else if (str[i] == ')')
        {
            StackTop(head, &top);
            while (top != '(' && top != '#')
            {
                StackPop(head, &x);
                *p = x;
                p++;
                StackTop(head, &top);
            }
            if (top == '#')
            {
                Destroy(head);
                return 0;
            }
            else
                StackPop(head, &x);
        }
        else
        {
            StackTop(head, &top);
            while (top != '(' && top != '#')
            {
                StackPop(head, &x);
                *p = x;
                p++;
                StackTop(head, &top);
            }
            if (top == '(')
            {
                Destroy(head);
                return 0;
            }
            else
                StackPop(head, &x);
        }
    }
    Destroy(head);
    return 1;
}
int main()
{
    int i;
    char str[] = A;
    char t[] = "#";
    strcat(str, t);
    char *a;
    if (!Transform(str, &a))
        printf("算式表达式错误！");
    else
    {
        for (i = 0; a[i] != '\0'; i++)
        {
            printf("%c", a[i]);
        }
    }
    free(a);
}