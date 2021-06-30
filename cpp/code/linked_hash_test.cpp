#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_hash.h"

int main()
{
    int n, count;
    scanf("%d", &n);
    LHTable *pt = ILH_Create(n);
    char dowhat[100];
    while (true)
    {
        count = 0;
        scanf("%s", dowhat);
        if (!strcmp(dowhat, "insert"))
        {
            int x;
            scanf("%d", &x);
            ILH_InsKey(pt, x);
        }
        else if (!strcmp(dowhat, "delete"))
        {
            int x;
            scanf("%d", &x);
            if (ILH_DelKey(pt, x, &count))
                printf("删除成功，");
            else
                printf("关键码不存在，删除失败，");
            printf("查找次数为%d\n", count);
        }
        else if (!strcmp(dowhat, "find"))
        {
            int x;
            scanf("%d", &x);
            if (ILH_FindKey(pt, x, &count))
                printf("查找成功，");
            else
                printf("关键码不存在，");
            printf("查找次数为%d\n", count);
        }
        else
        {
            break;
        }
    }
    ILH_Print(pt);
    ILH_Free(pt);
    system("PAUSE");
}
