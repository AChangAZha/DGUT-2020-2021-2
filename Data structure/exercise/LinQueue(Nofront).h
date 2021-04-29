/* 链式队列 */
typedef struct qnode
{
    DataType data;
    struct qnode *next;
}LQNode;
typedef struct
{
    LQNode *head;
    LQNode *rear;
}LQueue;
void QueueInitiate(LQueue *Q)
{
    Q->head=(LQNode *)malloc(sizeof(LQNode));
    Q->head->next=Q->head;
    Q->rear=NULL;
}
int QueueNotEmpty(LQueue Q)
{
    if(Q.head->next==Q.head) return 0;
    else return 1;
}
int QueueAppend(LQueue *Q,DataType x)
{
    LQNode *p;
    p=(LQNode *)malloc(sizeof(LQNode));
    p->data=x;
    p->next=Q->head;
    if(Q->rear!=NULL) Q->rear->next=p;
    Q->rear=p;
    if(Q->head->next==Q->head) Q->head->next=p;
}
int QueueDelete(LQueue *Q,DataType *d)
{
    LQNode *p;
    if(Q->head->next==Q->head)
    {
        printf("队列已空无数据元素出队列！\n");
        return 0;
    }
    else
    {
        *d=Q->head->next->data;
        p=Q->head->next;
        Q->head->next=p->next;
        if(Q->head->next==Q->head) Q->rear=NULL;
        free(p);
        return 1;
    }
}
int QueueGet(LQueue Q,DataType *d)
{
    if(Q.head->next==Q.head)
    {
        printf("队列已空无数据元素可取！\n");
        return 0;
    }
    else
    {
        *d=Q.head->next->data;
        return 1;
    }
}
void Destroy(LQueue Q)
{
    LQNode *p,*p1;
    p=Q.head->next;
    while(p!=Q.head)
    {
        p1=p;
        p=p->next;
        free(p1);
    }
    free(Q.head);
}