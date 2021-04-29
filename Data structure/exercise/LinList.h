/* 线性表：带头结点单链表 */
typedef struct Node
{
    DataType data;
    struct Node *next;
}SLNode;
void ListInitiate(SLNode **head)
{
    *head=(SLNode *)malloc(sizeof(SLNode));
    (*head)->next=NULL;
}
int ListLength(SLNode *head)
{
    SLNode *p=head;
    int size=0;
    while (p->next!=NULL)
    {
        p=p->next;
        size++;
    }
    return size;
}
int ListInsert(SLNode *head,int i,DataType x)
{
    SLNode *p,*q;
    int j;
    p=head;
    j=-1;
    while (p->next!=NULL && j<i-1)
    {
        p=p->next;
        j++;
    }
    if(j!=i-1)
    {
        printf("插入位置元素参数错！");
        return 0;
    }
    q=(SLNode *)malloc(sizeof(SLNode));
    q->data=x;
    q->next=p->next;
    p->next=q;
    return 1;
}
int ListDelete(SLNode *head,int i,DataType *x)
{
    SLNode *p,*s;
    int j;
    p=head;
    j=-1;
    while (p->next!=NULL && p->next->next!=NULL && j<i-1)
    {
        p=p->next;
        j++;
    }
    if(j!=i-1)
    {
        printf("删除元素位置参数错！");
        return 0;
    }
    s=p->next;
    *x=s->data;
    p->next=p->next->next;
    free(s);
    return 1;
}
int ListGet(SLNode *head,int i,DataType *x)
{
    SLNode *p;
    int j;
    p=head;
    j=-1;
    while (p->next!=NULL && j<i)
    {
        p=p->next;
        j++;
    }
    if(j!=i)
    {
        printf("取元素位置错！");
        return 0;
    }
    *x=p->data;
    return 1;
}
int Destroy(SLNode **head)
{
    SLNode *p,*p1;
    p=*head;
    while (p!=NULL)
    {
        p1=p;
        p=p->next;
        free(p1);
    }
    *head=NULL;
}
int ListDeleteMore(SLNode *L,DataType x)/* 删除所有指定元素x */
{
    int i=0;
    SLNode *p,*s;
    p=L;
    while(p->next!=NULL)
    {
        s=p->next;
        if(s->data==x)
        {
            p->next=p->next->next;
            free(s);
            i++;
        }
        else
        {
            p=p->next;
        }
    }
    return i;
}
void LinListInsert(SLNode *head,DataType x)/* 插入并保持升序 */
{
    SLNode *curr,*pre,*q;
    curr=head->next;
    pre=head;
    while(curr!=NULL && curr->data<=x)
    {
        pre=curr;
        curr=curr->next;
    }
    q=(SLNode *)malloc(sizeof(SLNode));
    q->data=x;
    q->next=pre->next;
    pre->next=q;
}
