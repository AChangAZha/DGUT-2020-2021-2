/* 顺序循环队列 */
#include <stdio.h>
#define MaxQueueSize 10
typedef int DataType;
#include "SeqCQueue(Norear).h"
void main()
{
    SeqCQueue myQueue;
    int i,x;
    QueueInitiate(&myQueue);
    for(i=0;i<11;i++)
    {
        QueueAppend(&myQueue,i+1);
        int a=myQueue.front,j;
        for(j=0;j<myQueue.count;j++)
        {
            printf("%d ",myQueue.queue[a%MaxQueueSize]);
            a++;
        }
        printf("\n%d\n",myQueue.count);
    }
    for(i=0;i<5;i++) 
    {
        QueueDelete(&myQueue,&x);
        int a=myQueue.front,j;
        for(j=0;j<myQueue.count;j++)
        {
            printf("%d ",myQueue.queue[a%MaxQueueSize]);
            a++;
        }
        printf("\n");
    }
    for(i=0;i<4;i++)
    {
        QueueAppend(&myQueue,i*2+1);
        int a=myQueue.front,j;
        for(j=0;j<myQueue.count;j++)
        {
            printf("%d ",myQueue.queue[a%MaxQueueSize]);
            a++;
        }
        printf("\n");
    }
    printf("当前队头数据元素是：");
    QueueGet(myQueue,&x);
    printf("%d\n",x);
    printf("依次出队列的数据元素序列如下：\n");
    while(QueueNotEmpty(myQueue))
    {
        QueueDelete(&myQueue,&x);
        printf("%d ",x);
    }
}