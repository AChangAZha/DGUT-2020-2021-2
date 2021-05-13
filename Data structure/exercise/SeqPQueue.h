/* 顺序优先级队列 */
typedef struct
{
    int priority;
    ElemType elem;
} DataType;
typedef struct
{
    DataType queue[MaxQueueSize];
    int size;
} SeqPQueue;
void QueueInitiate(SeqPQueue *Q)
{
    Q->size = 0;
}
int QueueNotEmpty(SeqPQueue Q)
{
    if (Q.size <= 0)
        return 0;
    else
        return 1;
}
int QueueAppend(SeqPQueue *Q, DataType x)
{
    if (Q->size >= MaxQueueSize)
    {
        printf("队列已满无法插入！\n");
        return 0;
    }
    else
    {
        Q->queue[Q->size] = x;
        Q->size++;
        return 1;
    }
}
int QueueDelete(SeqPQueue *Q, DataType *d)
{
    DataType min;
    int minIndex, i;
    if (Q->size <= 0)
    {
        printf("队列已空无数据元素出队列！\n");
        return 0;
    }
    else
    {
        min = Q->queue[0];
        minIndex = 0;
        for (i = 1; i < Q->size; i++)
        {
            if (Q->queue[i].priority < min.priority)
            {
                min = Q->queue[i];
                minIndex = i;
            }
        }
        *d = Q->queue[minIndex];
        for (i = minIndex + 1; i < Q->size; i++)
        {
            Q->queue[i - 1] = Q->queue[i];
        }
        Q->size--;
        return 1;
    }
}
int QueueGet(SeqPQueue *Q, DataType *d)
{
    DataType min;
    int minIndex, i;
    if (Q->size <= 0)
    {
        printf("队列已空无数据元素可取！\n");
        return 0;
    }
    else
    {
        min = Q->queue[0];
        minIndex = 0;
        for (i = 1; i < Q->size; i++)
        {
            if (Q->queue[i].priority < min.priority)
            {
                min = Q->queue[i];
                minIndex = i;
            }
        }
        *d = Q->queue[minIndex];
        return 1;
    }
}