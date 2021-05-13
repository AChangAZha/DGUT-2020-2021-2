/* 实验1.3 有序顺序表的操作和合并 */
#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
#include "1.3.h" //包含有序顺序表的操作函数
void main()
{
    void ListMerge(SeqList, SeqList, SeqList *);
    SeqList L1, L2, L3;
    int i;
    DataType x;
    char str1[] = "zhanghan", str2[] = "liangjie"; //测试数据
    printf("测试数据：\"%s\" \"%s\"\n", str1, str2);
    //初始化顺序表
    ListInitiate(&L1);
    ListInitiate(&L2);
    for (i = 0; str1[i] != '\0'; i++)
    {
        ListInsert(&L1, str1[i]); //有序插入
    }
    printf("L1长度为%d\n", ListLength(L1));
    ListDelete(&L1, 7, &x); //删除
    printf("删除元素L1.list[7]：%c\n", x);
    printf("L1长度为%d\n", ListLength(L1));
    for (i = 0; str2[i] != '\0'; i++)
    {
        ListInsert(&L2, str2[i]);
    }
    printf("L1：");
    for (i = 0; i < ListLength(L1); i++) //求元素个数
    {
        ListGet(L1, i, &x); //取数据元素
        printf("%c ", x);
    }
    printf("\n");
    printf("L2长度为%d\n", ListLength(L2));
    printf("L2：");
    for (i = 0; i < ListLength(L2); i++)
    {
        ListGet(L2, i, &x);
        printf("%c ", x);
    }
    printf("\n");
    ListMerge(L1, L2, &L3); //合并
    printf("合并后 L3：");
    for (i = 0; i < ListLength(L3); i++)
    {
        ListGet(L3, i, &x);
        printf("%c ", x);
    }
    printf("\n");
    printf("L3长度为%d\n", ListLength(L3));
    free(L1.list);
    free(L2.list);
    free(L3.list);
    scanf("%d", i);
}
void ListMerge(SeqList L1, SeqList L2, SeqList *L3) //合并函数
{
    int i1, i2, j;
    //动态申请内存空间
    L3->size = L1.size + L2.size;
    L3->list = (DataType *)calloc(L3->size, sizeof(DataType));
    i1 = L1.size - 1; //i1指向数组L1的最后一个元素
    i2 = L2.size - 1; //i2指向数组L2的最后一个元素
    j = L3->size - 1; //j指向数组L3的最后一个元素
    while (i1 >= 0 && i2 >= 0)
    {
        //对比L1和L2数组的最后一个元素
        if (L1.list[i1] > L2.list[i2])
        {
            //将较大者从L3末尾开始放入
            L3->list[j] = L1.list[i1];
            //i1往前移，i2不变，继续比较L1.list[i1]和L2.list[i2]
            i1--;
        }
        else
        {
            L3->list[j] = L2.list[i2];
            i2--;
        }
        j--; //j往前移
    }
    if (i1 >= 0) //将剩下没有参与比较的元素依次放入L3
    {
        while (i1 >= 0)
        {
            L3->list[j] = L1.list[i1];
            i1--;
            j--;
        }
    }
    if (i2 >= 0)
    {
        while (i2 >= 0)
        {
            L3->list[j] = L2.list[i2];
            i2--;
            j--;
        }
    }
}