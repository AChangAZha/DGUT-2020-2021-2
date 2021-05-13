/* 链式队列 */
typedef struct qnode
{
    DataType data;
    struct qnode *next;
} LQNode;
typedef struct
{
    LQNode *front;
    LQNode *rear;
} LQueue;
void QueueInitiate(LQueue *Q)
{
    Q->rear = NULL;
    Q->front = NULL;
}
int QueueNotEmpty(LQueue Q)
{
    if (Q.front == NULL)
        return 0;
    else
        return 1;
}
int QueueAppend(LQueue *Q, DataType x)
{
    LQNode *p;
    p = (LQNode *)malloc(sizeof(LQNode));
    p->data = x;
    p->next = NULL;
    if (Q->rear != NULL)
        Q->rear->next = p;
    Q->rear = p;
    if (Q->front == NULL)
        Q->front = p;
}
int QueueDelete(LQueue *Q, DataType *d)
{
    LQNode *p;
    if (Q->front == NULL)
    {
        printf("队列已空无数据元素出队列！\n");
        return 0;
    }
    else
    {
        *d = Q->front->data;
        p = Q->front;
        Q->front = Q->front->next;
        if (Q->front == NULL)
            Q->rear = NULL;
        free(p);
        return 1;
    }
}
int QueueGet(LQueue Q, DataType *d)
{
    if (Q.front == NULL)
    {
        printf("队列已空无数据元素可取！\n");
        return 0;
    }
    else
    {
        *d = Q.front->data;
        return 1;
    }
}
void Destroy(LQueue Q)
{
    LQNode *p, *p1;
    p = Q.front;
    while (p != NULL)
    {
        p1 = p;
        p = p->next;
        free(p1);
    }
}