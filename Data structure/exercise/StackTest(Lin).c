/* 链式堆栈 */
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
#include "LinStack.h"
void main()
{
    LSNode *head;
    int i, x;
    StackInitiate(&head);
    for (i = 0; i < 10; i++)
        StackPush(head, i + 1);
    StackTop(head, &x);
    printf("当前栈顶数据元素为：%d\n", x);
    printf("依次出栈的数据元素序列如下：\n");
    while (StackNotEmpty(head))
    {
        StackPop(head, &x);
        printf("%d ", x);
    }
    Destroy(head);
}