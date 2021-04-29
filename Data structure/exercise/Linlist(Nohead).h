/* 线性表：不带头节点单链表 */
int ListInsert(SLNode **L,int i,DataType x)
{
	SLNode *p,*s;
	int j;
	if(i<0) return 0;
	if(i==0)
    {
		s=(SLNode *)malloc(sizeof(SLNode));
		s->data=x;
		s->next=*L;
		*L=s;//头指针指向新结点 
		return 1; 
	}
	p=*L;
    j=0;
    while (p->next!=NULL && j<i-1)
    {
        p=p->next;
        j++;
    }
    if(j!=i-1) return 0;
    s=(SLNode *)malloc(sizeof(SLNode));
    s->data=x;
    s->next=p->next;
    p->next=s;
    return 1;
}

int ListDelete(SLNode **L,int i,DataType *x)
{
    SLNode *p,*s;
    int j;
	if(i<0) return 0;
	if(i==0)
	{
		s=*L;
		*x=s->data;
		*L=(*L)->next;
		free(s);
		return 1;
	}
    p=*L;
    j=0;
    while (p->next!=NULL && p->next->next!=NULL && j<i-1)
    {
        p=p->next;
        j++;
    }
    if(j!=i-1) return 0;
    s=p->next;
    *x=s->data;
    p->next=p->next->next;
    free(s);
    return 1;
}