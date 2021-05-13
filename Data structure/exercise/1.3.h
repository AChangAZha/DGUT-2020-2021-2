/* 有序顺序表 */
typedef struct
{
    DataType *list; //动态数组
    int size;
} SeqList;
void ListInitiate(SeqList *L) //初始化
{
    L->size = 0;
    L->list = NULL;
}
int ListLength(SeqList L)
{
    return L.size;
}
int ListInsert(SeqList *L, DataType x) //插入并保持升序
{
    int i, j;
    //增加动态数组的元素个数
    L->list = (DataType *)realloc(L->list, (L->size + 1) * sizeof(DataType));
    for (i = 0; i < L->size; i++) //定位，找到第一个比x大的元素
    {
        if (L->list[i] > x)
            break;
    }
    for (j = L->size; j > i; j--) //从定位元素开始依次往后移
    {
        L->list[j] = L->list[j - 1];
    }
    L->list[i] = x; //插入x
    L->size++;      //元素个数加1
    return 1;
}
int ListDelete(SeqList *L, int i, DataType *x) //删除
{
    int j;
    if (L->size <= 0)
    {
        printf("顺序表已空无数据元素可删！\n");
        return 0;
    }
    else if (i < 0 || i > L->size - 1)
    {
        printf("参数i不合法\n");
        return 0;
    }
    else
    {
        *x = L->list[i];
        for (j = i + 1; j <= L->size - 1; j++)
        {
            L->list[j - 1] = L->list[j];
        }
        L->size--;
        return 1;
    }
}
int ListGet(SeqList L, int i, DataType *x) //取数据元素
{
    if (i < 0 || i > L.size - 1)
    {
        printf("参数i不合法！\n");
        return 0;
    }
    else
    {
        *x = L.list[i];
        return 1;
    }
}