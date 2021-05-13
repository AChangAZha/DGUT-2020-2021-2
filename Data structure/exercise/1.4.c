/* 实验1.4 十进制转换为d进制 */
#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
#include "LinStack.h" //包含堆栈的操作函数
int main()
{
    LSNode *head;
    int x, d;
    char t;
    StackInitiate(&head); //初始化堆栈
    printf("请输入一个非负十进制整数：");
    scanf("%d", &x);
    printf("请输入整数d（2≤d≤36）：");
    scanf("%d", &d);
    printf("非负十进制整数%d转化为%d进制数：", x, d);
    do
    {
        //当余数为0~9时，将余数入栈
        if (x % d <= 9)
            StackPush(head, '0' + x % d);
        //当余数大于9时，用字母A~Z表示余数，入栈
        else
            StackPush(head, 'A' + x % d - 10);
        x = x / d; //取整
    } while (x != 0);
    while (StackNotEmpty(head))
    {
        StackPop(head, &t); //出栈
        printf("%c", t);
    }
    Destroy(head);
}