#include <stdio.h>
#define MaxSize 24
typedef struct
{
    int i;
    int j;
    int d;
} DataType;
typedef struct
{
    int md;
    int nd;
    int td;
} TriType;
typedef struct
{
    DataType list[MaxSize];
} SeqList;
int main()
{
    void Add(TriType A, SeqList a, TriType B, SeqList b, TriType * C, SeqList * c);
    void Print(TriType A, SeqList a);
    TriType A, B, C;
    SeqList a, b, c;
    a.list[0].i = 1;
    a.list[0].j = 3;
    a.list[0].d = 9;
    a.list[1].i = 2;
    a.list[1].j = 2;
    a.list[1].d = 5;
    a.list[2].i = 2;
    a.list[2].j = 6;
    a.list[2].d = 1;
    a.list[3].i = 3;
    a.list[3].j = 1;
    a.list[3].d = 4;
    a.list[4].i = 3;
    a.list[4].j = 6;
    a.list[4].d = 2;
    a.list[5].i = 4;
    a.list[5].j = 4;
    a.list[5].d = 8;
    b.list[0].i = 1;
    b.list[0].j = 1;
    b.list[0].d = 1;
    b.list[1].i = 1;
    b.list[1].j = 6;
    b.list[1].d = 3;
    b.list[2].i = 2;
    b.list[2].j = 3;
    b.list[2].d = 5;
    b.list[3].i = 3;
    b.list[3].j = 5;
    b.list[3].d = 7;
    b.list[4].i = 4;
    b.list[4].j = 2;
    b.list[4].d = 9;
    A.md = 4;
    A.nd = 6;
    A.td = 6;
    B.md = 4;
    B.nd = 6;
    B.td = 5;
    Add(A, a, B, b, &C, &c);
    printf("A:\n");
    Print(A, a);
    printf("B\n");
    Print(B, b);
    printf("C\n");
    Print(C, c);
}
void Add(TriType A, SeqList a, TriType B, SeqList b, TriType *C, SeqList *c)
{
    int n = 0, m = 0, t = 0;
    C->md = A.md;
    C->nd = A.nd;
    while (n < A.td && m < B.td)
    {
        if (a.list[n].i == b.list[m].i)
        {
            if (a.list[n].j == b.list[m].j)
            {
                c->list[t].i = a.list[n].i;
                c->list[t].j = a.list[n].j;
                c->list[t].d = a.list[n].d + a.list[n].d;
                n++;
                m++;
            }
            else if (a.list[n].j < b.list[m].j)
            {
                c->list[t].i = a.list[n].i;
                c->list[t].j = a.list[n].j;
                c->list[t].d = a.list[n].d;
                n++;
            }
            else
            {
                c->list[t].i = b.list[m].i;
                c->list[t].j = b.list[m].j;
                c->list[t].d = b.list[m].d;
                m++;
            }
        }
        else if (a.list[n].i < b.list[m].i)
        {
            c->list[t].i = a.list[n].i;
            c->list[t].j = a.list[n].j;
            c->list[t].d = a.list[n].d;
            n++;
        }
        else
        {
            c->list[t].i = b.list[m].i;
            c->list[t].j = b.list[m].j;
            c->list[t].d = b.list[m].d;
            m++;
        }
        t++;
    }
    while (n < A.td)
    {
        c->list[t].i = a.list[n].i;
        c->list[t].j = a.list[n].j;
        c->list[t].d = a.list[n].d;
        n++;
        t++;
    }
    while (m < B.td)
    {
        c->list[t].i = b.list[m].i;
        c->list[t].j = b.list[m].j;
        c->list[t].d = b.list[m].d;
        m++;
        t++;
    }
    C->td = t;
}
void Print(TriType A, SeqList a)
{
    int i, j, t = 0;
    for (i = 1; i <= A.md; i++)
    {
        for (j = 1; j <= A.nd; j++)
        {
            if (i == a.list[t].i && j == a.list[t].j)
            {
                printf("%d ", a.list[t].d);
                t++;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}