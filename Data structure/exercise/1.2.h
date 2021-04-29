/* 顺序循环队列 */
typedef struct
{
    DataType queue[MaxQueueSize];
    int rear;
    int front;
}SeqCQueue;
void QueueInitiate(SeqCQueue *Q) //初始化
{
    Q->rear=0;
    Q->front=0;
}
int QueueEmpty(SeqCQueue Q) //判断队列Q是否为空
{
    return(Q.rear==Q.front); //若为空返回1，否则返回0
}
int QueueAppend(SeqCQueue *Q,DataType x) //入队
{
    if((Q->rear+1)%MaxQueueSize==Q->front)
    {
        printf("队列已满无法插入！\n");
        return 0;
    }
    else
    {
        Q->queue[Q->rear]=x;
        Q->rear=(Q->rear+1)%MaxQueueSize;
        return 1;
    }
}
int QueueDelete(SeqCQueue *Q,DataType *d) //出队
{
    if(Q->rear==Q->front)
    {
        printf("队列已空无数据元素出队列！\n");
        return 0;
    }
    else
    {
        *d=Q->queue[Q->front];
        Q->front=(Q->front+1)%MaxQueueSize;
        return 1;
    }
}
void QueueLength(SeqCQueue Q) //输出队列元素个数
{
    int len;
    if(Q.rear>=Q.front) len=Q.rear-Q.front;
    else len=Q.rear+MaxQueueSize-Q.front;
    printf("%d\n",len);
}
void QueuePrint(SeqCQueue Q) //输出队列序列
{
    int i,len;
    if(Q.rear>=Q.front) len=Q.rear-Q.front;
    else len=Q.rear+MaxQueueSize-Q.front;
    if(len==0) printf("队列为空");
    else
    {
        for(i=0;i<len;i++)
        {
            printf("%c ",Q.queue[(Q.front+i)%MaxQueueSize]);
        }
    }
    printf("\n");
}