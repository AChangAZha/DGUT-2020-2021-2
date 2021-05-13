/* 线性表就地逆置 */
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;

#include "LinList.h"
void Lin(SLNode *head) /* 单链表 */
{
    SLNode *p, *q, *j;
    p = head->next;
    head->next = NULL;
    while (p != NULL)
    {
        /*向后挪动一个位置*/
        q = p;
        p = p->next;
        /*头插*/
        q->next = head->next;
        head->next = q;
        /* j=head->next;
        while(j!=NULL)
        {
            printf("%d ",j->data);
            j=j->next;
        }
        printf("\n"); */
    }
}
void main()
{
    SLNode *L1, *p;
    int i, x;
    ListInitiate(&L1);
    for (i = 0; i < 5; i++)
    {
        ListInsert(L1, i, i * 2);
        /* p=L1->next;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n"); */
    }
    for (i = 0; i < ListLength(L1); i++)
    {
        ListGet(L1, i, &x);
        printf("%d ", x);
    }
    printf("\n");
    Lin(L1);
    for (i = 0; i < ListLength(L1); i++)
    {
        ListGet(L1, i, &x);
        printf("%d ", x);
    }
    printf("\n");
    Destroy(&L1);
}

// #define MaxSize 100
// #include "SeqList.h"
// int Seq(SeqList *L)/* 顺序表 */
// {
//     int i,n=L->size,m=(L->size)/2,x,j;
//     DataType temp;
//     for(i=0;i<m;i++)
//     {
//         temp=L->list[i];
//         L->list[i]=L->list[n-1-i];
//         L->list[n-1-i]=temp;
//       /* for(j=0;j<ListLength(*L);j++)
//       {
//           ListGet(*L,j,&x);
//           printf("%d ",x);
//       }
//         printf("\n"); */
//     }
// }
// void main()
// {
//     SeqList mylist;
//     int i,x,j;
//     ListInitiate(&mylist);
//     for(i=0;i<10;i++)
//     {
//         f(&mylist,99-i);
//         /* for(j=0;j<ListLength(mylist);j++)
//         {
//             ListGet(mylist,j,&x);
//             printf("%d ",x);
//         }
//         printf("\n"); */
//     }
//     for(j=0;j<ListLength(mylist);j++)
//     {
//         ListGet(mylist,j,&x);
//         printf("%d ",x);
//     }
//     printf("\n");
//     Seq(&mylist);
//     for(i=0;i<ListLength(mylist);i++)
//     {
//         ListGet(mylist,i,&x);
//         printf("%d ",x);
//     }
//     printf("\n");
// }