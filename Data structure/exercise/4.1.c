#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000
void creatArray(int array[], int num)
{
    int i;
    srand((unsigned)time(NULL));
    for (i = 0; i < num; i++)
    {
        // array[i] = 10-i;
        array[i] = rand() % 10001;
    }
}
void QuickSort(int array[], int low, int high, int *com, int *exc)
{
    int i = low, j = high;
    int temp = array[low];
    while (i < j)
    {
        while (i < j)
        {
            (*com)++;
            if (temp > array[j])
                break;
            j--;
        }
        if (i < j)
        {
            (*exc)++;
            array[i] = array[j];
            i++;
        }
        while (i < j)
        {
            (*com)++;
            if (array[i] >= temp)
                break;
            i++;
        }
        if (i < j)
        {
            (*exc)++;
            array[j] = array[i];
            j--;
        }
    }
    array[i] = temp;
    if (low < i)
        QuickSort(array, low, i - 1, com, exc);
    if (i < high)
        QuickSort(array, j + 1, high, com, exc);
}
void CreatHeap(int array[], int n, int h, int *com, int *exc)
{
    int i, j, flag, temp;
    i = h;
    j = 2 * i + 1;
    temp = array[i];
    flag = 0;
    while (j < n && flag != 1)
    {
        (*com) += 2;
        if (j < n - 1 && array[j] > array[j + 1])
            j++;
        if (temp < array[j])
            flag = 1;
        else
        {
            array[i] = array[j];
            (*exc)++;
            i = j;
            j = 2 * i + 1;
        }
    }
    array[i] = temp;
}
void InitCreatHeap(int array[], int n)
{
    int i, com = 0, exc = 0;
    for (i = (n - 2) / 2; i >= 0; i--)
        CreatHeap(array, n, i, &com, &exc);
    printf("堆排序\n创建最小堆时，比较次数（左右孩子结点比较+双亲结点和孩子结点比较）：%d，交换次数：%d\n", com, exc);
}
void HeapSort(int array[], int n)
{
    int i, temp, com = 0, exc = 0;
    InitCreatHeap(array, n);
    for (i = n - 1; i > 0; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        CreatHeap(array, i, 0, &com, &exc);
    }
    printf("排序时，比较次数：%d，交换次数（交换顶点+调整为最小堆）：%d\n", com, exc + n - 1);
}
int main()
{
    int i, com = 0, exc = 0;
    int array[MAX];
    creatArray(array, MAX);
    // HeapSort(array, MAX);
    QuickSort(array, 0, MAX - 1, &com, &exc);
    printf("快速排序\n比较次数：%d，交换次数：%d\n", com, exc);
    for (i = 0; i < MAX; i++)
    {
        printf("%-5d", array[i]);
    }
    system("pause");
}