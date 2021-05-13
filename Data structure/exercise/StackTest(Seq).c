/* 顺序堆栈 */
#include <stdio.h>
#define MaxStackSize 100
typedef int DataType;
#include "SeqStack.h"
void main()
{
    SeqStack myStack;
    int i, x;
    StackInitiate(&myStack);
    for (i = 0; i < 10; i++)
        StackPush(&myStack, i + 1);
    StackTop(myStack, &x);
    printf("当前栈顶数据元素为：%d\n", x);
    printf("依次出栈的数据元素序列如下：\n");
    while (StackNotEmpty(myStack))
    {
        StackPop(&myStack, &x);
        printf("%d ", x);
    }
}