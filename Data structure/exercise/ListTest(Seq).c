/* 顺序表 */
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int DataType;
#include "SeqList.h"
void main()
{
    SeqList myList;
    int i,x;
    ListInitiate(&myList);
    for(i=0;i<10;i++)
    {
        f(&myList,99-i);
    }
    ListDelete(&myList,10,&x);
    for(i=0;i<ListLength(myList);i++)
    {
        ListGet(myList,i,&x);
        printf("%d \n",x);
    }
}