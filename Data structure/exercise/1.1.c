/* 实验1.1 多项式 */
#include <stdio.h>
#include <stdlib.h>
#include "1.1.h"
void main()
{
    SLNode *P,*Q,*plus,*minus;
    double a;
    int b;
    ListInitiate(&P); //多项式链表初始化
    ListInitiate(&Q);
    printf("以(系数,指数)方式输入多项式p(x)的项（当系数为0时结束输入）:\n");
    do
    {
        scanf("(%lf,%d)",&a,&b); //以(a,b)的方式输入
        getchar();
        if(a==0) break; //当系数为0时结束输入
        ListInsert(P,a,b); //有序插入，建立有序链表
    }while(1);
    printf("以(系数,指数)方式输入多项式q(x)的项（当系数为0时结束输入）:\n");
    do
    {
        scanf("(%lf,%d)",&a,&b);
        getchar();
        if(a==0) break;
        ListInsert(Q,a,b);
    }while(1);
    plus=ListPlus(P,Q); //多项式相加
    minus=ListMinus(P,Q); //多项式相减
    printf("p(x)=");
    ListPrint(P); //多项式输出
    printf("q(x)=");
    ListPrint(Q);
    printf("p(x)+q(x)=");
    ListPrint(plus);
    printf("p(x)-q(x)=");
    ListPrint(minus);
    Destroy(&P);
    Destroy(&Q);
    Destroy(&plus);
    Destroy(&minus);
}