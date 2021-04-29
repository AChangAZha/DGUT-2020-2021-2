/* 判断子集 */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
typedef int DataType;
#include "LinList.h"
int F(SLNode *L1,SLNode *L2)
{
    SLNode *p=L1,*q=L2;
    while (p->next!=NULL && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
        if(p->next!=NULL && q->next==NULL)
        {
            printf("L1不是L2的子集\n");
            return 0;
        }
    }
    p=L1;
    while(p->next!=NULL)
    {
        q=L2;
        while (q->next!=NULL)
        {
            if(p->next->data==q->next->data) break;
            q=q->next;
        }
        if(q->next==NULL)
        {
            printf("L1不是L2的子集\n");
            return 0;
        }
        p=p->next;
    }
    printf("L1是L2的子集\n");
    return 1;
}
void main()
{
    SLNode *L1,*L2;
    int i,x;
    ListInitiate(&L1);
    ListInitiate(&L2);
    for(i=0;i<5;i++)
    {
        ListInsert(L1,i,i*2);
    }
    for(i=0;i<10;i++)
    {
        ListInsert(L2,i,i*2);
    }
    F(L1,L2);
    for(i=0;i<ListLength(L1);i++)
    {
        ListGet(L1,i,&x);
        printf("%d ",x);
    }
    printf("\n");
    for(i=0;i<ListLength(L2);i++)
    {
        ListGet(L2,i,&x);
        printf("%d ",x);
    }
    Destroy(&L1);
    Destroy(&L2);
}
