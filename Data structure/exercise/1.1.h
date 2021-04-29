/* 多项式操作 */
typedef struct Node
{
    double a; //系数
    int b; //指数
    struct Node *next;
}SLNode;
void ListInitiate(SLNode **head) //初始化
{
    *head=(SLNode *)malloc(sizeof(SLNode));
    (*head)->next=NULL;
}
SLNode *ListInsert(SLNode *head,double a,int b) //多项式链表建立，保证有序
{
    SLNode *curr,*pre,*q;
    curr=head->next; //curr指向第一项
    pre=head; //pre指向头结点
    //定位，从第一项开始寻找第一个大于或等于b的元素
    while(curr!=NULL && curr->b<=b)
    {
        pre=curr;
        curr=curr->next;
    }
    //如果找到与b相等的元素，合并同类项
    if(pre->b==b)
    {
        pre->a=pre->a+a;
        return head; //返回头指针
    }
    //插入新的项
    q=(SLNode *)malloc(sizeof(SLNode));
    q->a=a;
    q->b=b;
    q->next=pre->next;
    pre->next=q;
    return head;
}
SLNode *ListPlus(SLNode *P,SLNode *Q) //多项式相加
{
    SLNode *head,*p,*q;
    int a,b;
    head=(SLNode *)malloc(sizeof(SLNode)); //申请新多项式的头结点
    head->next=NULL;
    //循环初始化
    p=head;
    P=P->next;
    Q=Q->next;
    //建立新多项式，并保证有序
    while (P!=NULL && Q!=NULL)
    {
        //从两个多项式的第一项开始比较大小
        if(P->b<Q->b)
        {
            a=P->a;
            b=P->b;
            P=P->next; //P后移，Q不动
        }
        else if(Q->b<P->b)
        {
            a=Q->a;
            b=Q->b;
            Q=Q->next; //Q后移，P不动
        }
        else if(P->b==Q->b) //合并同类项
        {
            a=P->a+Q->a;
            b=P->b;
            //P,Q均后移
            P=P->next;
            Q=Q->next;
        }
        q=(SLNode *)malloc(sizeof(SLNode));
        q->a=a;
        q->b=b;
        q->next=p->next;
        p->next=q;
        p=p->next;
    }
    //若上述循环结束后P或Q中还有元素未放入新多项式，依次放入
    while (P!=NULL)
    {
        q=(SLNode *)malloc(sizeof(SLNode));
        q->a=P->a;
        q->b=P->b;
        q->next=p->next;
        p->next=q;
        p=p->next;
        P=P->next;
    }
    while (Q!=NULL)
    {
        q=(SLNode *)malloc(sizeof(SLNode));
        q->a=Q->a;
        q->b=Q->b;
        q->next=p->next;
        p->next=q;
        p=p->next;
        Q=Q->next;
    }
    return head; //返回新多项式的头指针
}
SLNode *ListMinus(SLNode *P,SLNode *Q) //多项式相减
{
    SLNode *head,*p,*q;
    int a,b;
    head=(SLNode *)malloc(sizeof(SLNode));
    head->next=NULL;
    p=head;
    P=P->next;
    Q=Q->next;
    while (P!=NULL && Q!=NULL)
    {
        if(P->b<Q->b)
        {
            a=P->a;
            b=P->b;
            P=P->next;
        }
        else if(Q->b<P->b)
        {
            a=-Q->a; //将多项式Q中所有系数的相反数放入新多项式
            b=Q->b;
            Q=Q->next;
        }
        else if(P->b==Q->b)
        {
            a=P->a-Q->a; //同类项相减
            b=P->b;
            P=P->next;
            Q=Q->next;
        }
        q=(SLNode *)malloc(sizeof(SLNode));
        q->a=a;
        q->b=b;
        q->next=p->next;
        p->next=q;
        p=p->next;
    }
    while (P!=NULL)
    {
        q=(SLNode *)malloc(sizeof(SLNode));
        q->a=P->a;
        q->b=P->b;
        q->next=p->next;
        p->next=q;
        p=p->next;
        P=P->next;
    }
    while (Q!=NULL)
    {
        q=(SLNode *)malloc(sizeof(SLNode));
        q->a=-Q->a; //将多项式Q中所有系数的相反数放入新多项式
        q->b=Q->b;
        q->next=p->next;
        p->next=q;
        p=p->next;
        Q=Q->next;
    }
    return head;
}
void ListPrint(SLNode *head) //多项式的输出
{
    SLNode *p;
    int i=0; //i用于判断多项式是否为0
    for(p=head->next;p!=NULL;p=p->next)
    {
        if(p->a==0) continue; //如果系数为0，继续下一次循环
        if(i==1) printf("+");
        i=1; //i=1，多项式不为0
        if(p->a<0) printf("(%.0lf)",p->a); //若系数小于0，系数需带上括号
        if(p->a>0) printf("%.0lf",p->a);
        if(p->b!=0) printf("x%d",p->b); //若指数为0，不输出x
    }
    if(i==0) printf("0"); //若多项式为0，输出0
    printf("\n");
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