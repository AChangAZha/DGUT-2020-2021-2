/* 链式队列 */
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
#include "LinQueue(Nofront).h"
void main()
{
    LQueue Q;
    LQNode *p;
    int i, x;
    QueueInitiate(&Q);
    for (i = 0; i < 10; i++)
    {
        QueueAppend(&Q, i + 1);
        p = Q.head->next;
        while (p != Q.head)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
    for (i = 0; i < 10; i++)
    {
        QueueDelete(&Q, &x);
        p = Q.head->next;
        while (p != Q.head)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
    QueueGet(Q, &x);
    printf("当前队头数据元素为：%d\n", x);
    printf("依次出队列的数据元素序列如下：\n");
    /* while(QueueNotEmpty(Q))
    {
        QueueDelete(&Q,&x);
        printf("%d ",x);
    } */
    Destroy(Q);
}