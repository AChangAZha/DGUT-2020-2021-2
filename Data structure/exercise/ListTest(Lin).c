/* 线性表：链表 */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef int DataType;
#include "Linlist.h"
int main()
{
    SLNode *head, *p;
    int i;
    ListInitiate(&head);
    for (i = 0; i < 1000; i++)
    {
        int a = rand()%10001;
        ListInsert(head, i,a);
    }
    InsertSort(head);
    p = head->next;
    for (i = 0; i < ListLength(head); i++)
    {
        printf("%-5d", p->data);
        p = p->next;
    }
    Destroy(&head);
}