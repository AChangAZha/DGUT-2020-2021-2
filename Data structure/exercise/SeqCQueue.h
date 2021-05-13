/* 顺序循环队列 */
typedef struct
{
    DataType queue[MaxQueueSize];
    int rear;
    int front;
    int count;
} SeqCQueue;
void QueueInitiate(SeqCQueue *Q)
{
    Q->rear = 0;
    Q->front = 0;
    Q->count = 0;
}
int QueueNotEmpty(SeqCQueue Q)
{
    if (Q.count != 0)
        return 1;
    else
        return 0;
}
int QueueAppend(SeqCQueue *Q, DataType x)
{
    if (Q->count > 0 && Q->rear == Q->front)
    {
        printf("队列已满无法插入！\n");
        return 0;
    }
    else
    {
        Q->queue[Q->rear] = x;
        Q->rear = (Q->rear + 1) % MaxQueueSize;
        Q->count++;
        return 1;
    }
}
int QueueDelete(SeqCQueue *Q, DataType *d)
{
    if (Q->count == 0)
    {
        printf("队列已空无数据元素出队列！\n");
        return 0;
    }
    else
    {
        *d = Q->queue[Q->front];
        Q->front = (Q->front + 1) % MaxQueueSize;
        Q->count--;
        return 1;
    }
}
int QueueGet(SeqCQueue Q, DataType *d)
{
    if (Q.count == 0)
    {
        printf("队列已空无数据元素可取！\n");
        return 0;
    }
    else
    {
        *d = Q.queue[Q.front];
        return 1;
    }
}