/* 线性表：顺序表 */
typedef struct
{
    DataType list[MaxSize];
    int size;
}SeqList;
void ListInitiate(SeqList *L)
{
    L->size=0;
}
int ListLength(SeqList L)
{
    return L.size;
}
int ListInsert(SeqList *L,int i,DataType x)
{
    int j;
    if(L->size>=MaxSize)
    {
        printf("顺序表已满无法插入！\n");
        return 0;
    }
    else if(i<0 || i>L->size)
    {
        printf("参数i不合法！\n");
        return 0;
    }
    else
    {
        for(j=L->size;j>i;j--)
        {
            L->list[j]=L->list[j-1];
        }
        L->list[i]=x;
        L->size++;
        return 1;
    }
}
int ListDelete(SeqList *L,int i,DataType *x)
{
    int j;
    if(L->size<=0)
    {
        printf("顺序表已空无数据元素可删！\n");
        return 0;
    }
    else if(i<0 || i>L->size-1)
    {
        printf("参数i不合法");
        return 0;
    }
    else
    {
        *x=L->list[i];
        for(j=i+1;j<=L->size-1;j++)
        {
            L->list[j-1]=L->list[j];
        }
        L->size--;
        return 1;
    }
}
int ListGet(SeqList L,int i,DataType *x)
{
    if(i<0 || i>L.size-1)
    {
        printf("参数i不合法！\n");
        return 0;
    }
    else
    {
        *x=L.list[i];
        return 1;
    }
}
int ListFind(SeqList L,DataType x)/* 定位 */
{
    int i;
    for(i=0;i<L.size;i++)
    {
        if(L.list[i]==x)
        {
            return i;
        }
    }
    return -1;
}
int f(SeqList *L,DataType x)/* 插入并保持升序 */
{
    int i,j;
    if(L->size>=MaxSize)
    {
        printf("顺序表已满无法插入！\n");
        return 0;
    }
    for(i=0;i<L->size;i++) /* 找到第一个比x大的元素 */
    {
        if(L->list[i]>x) break;
    }
    for(j=L->size;j>i;j--)/* 往后移 */
    {
        L->list[j]=L->list[j-1];
    }
    L->list[i]=x;
    L->size++;
    return 1;
}