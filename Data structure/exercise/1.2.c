/* 顺序循环队列 */
#include <stdio.h>
#define MaxQueueSize 10 //最大可存放元素个数为10-1=9
typedef char DataType;
#include "1.2.h"
void main()
{
    SeqCQueue myQueue;
    int i;
    DataType x;
    char str[] = "zhanghan"; //测试数据
    printf("测试数据：%s\n", str);
    QueueInitiate(&myQueue); //初始化
    for (i = 0; str[i] != '\0'; i++)
    {
        QueueAppend(&myQueue, str[i]); //入队
    }
    QueueDelete(&myQueue, &x);   //出队
    printf("出队元素：%c\n", x); //输出出队元素
    printf("当前队列状态：\n");
    printf("1.输出队列元素：");
    QueuePrint(myQueue);                                             //输出队列序列
    printf("2.是否为空：%s\n", (QueueEmpty(myQueue) ? "是" : "否")); //判断是否为空
    printf("3.队列元素个数：");
    QueueLength(myQueue); //输出队列元素个数
}