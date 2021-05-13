/* 线性表：链表 */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef int DataType;
#include "Linlist.h"
void main()
{
    SLNode *head, *p;
    int i, x;
    ListInitiate(&head);
    for (i = 0; i < 10; i++)
    {
        int a = rand();
        LinListInsert(head, i);
    }
    ListDelete(head, 10, &x);
    p = head->next;
    for (i = 0; i < ListLength(head); i++)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    Destroy(&head);
}