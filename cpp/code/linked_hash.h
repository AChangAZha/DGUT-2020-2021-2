struct HNode
{            //哈希结点
    int key; ////假设关键码为整数
    HNode *next;
};
struct LHTable
{
    HNode *pn; //指向散列表，每个表结点是独立链表的表头结点
    int n;     ////散列表的长度，一般取（小于等于数据个数的最大）质数
};

LHTable *ILH_Create(int n);
void ILH_Free(LHTable *pt);
bool ILH_InsKey(LHTable *pt, int x);
bool ILH_FindKey(LHTable *pt, int x, int *count);
bool ILH_DelKey(LHTable *pt, int x, int *count);
void ILH_Print(LHTable *pt);

LHTable *ILH_Create(int n)
//创建散列表, n为表长度，最佳取值：n取小于等于数据个数的最大质数
{
    HNode *pn = (HNode *)malloc(sizeof(HNode) * n);
    for (int i = 0; i < n; i++)
    {
        pn[i].key = 0;
        pn[i].next = NULL;
    }
    LHTable *pt = (LHTable *)malloc(sizeof(LHTable));
    pt->pn = pn;
    pt->n = n;
    return pt;
}

void ILH_Free(LHTable *pt)
//释放散列表
{
    if (pt == NULL)
        return;
    for (int i = 0; i < pt->n; i++)
    {
        HNode *curr = pt->pn[i].next;
        while (curr)
        {
            HNode *next = curr->next;
            free(curr);
            curr = next;
        }
    }
    free(pt->pn);
    free(pt);
}

bool ILH_InsKey(LHTable *pt, int x)
//插入关键码x
//返回true，表示插入成功
//返回false，表示插入失败(关键码已经存在)
{
    /*请在BEGIN和END之间实现你的代码*/
    /*****BEGIN*****/
    int d = x % pt->n;
    if (pt->pn[d].key == 0)
    {
        pt->pn[d].key = x;
        return true;
    }
    else if (pt->pn[d].key == x)
        return false;

    HNode *pre = &(pt->pn[d]);
    while (pre->next != NULL)
    {
        if (pre->next->key == x)
            return false;
        pre = pre->next;
    }
    HNode *n = (HNode *)malloc(sizeof(HNode));
    n->key = x;
    n->next = NULL;
    pre->next = n;
    return true;

    /******END******/
    /*请不要修改[BEGIN,END]区域外的代码*/
}

bool ILH_FindKey(LHTable *pt, int x, int *count)
//查找关键码x
//返回true表示找到
//返回false表示没找到
{
    int d = x % pt->n;
    (*count)++;
    if (pt->pn[d].key == 0)
    {
        return false;
    }
    else if (pt->pn[d].key == x)
        return true;

    HNode *curr = pt->pn[d].next;
    while (curr && curr->key != x)
    {
        (*count)++;
        curr = curr->next;
    }

    if (curr)
    {
        (*count)++;
        return true;
    }
    else
        return false;
}

bool ILH_DelKey(LHTable *pt, int x, int *count)
//删除关键码
//返回true表示该关键码存在，且成功删除
//返回false表示该关键码不存在
{
    /*请在BEGIN和END之间实现你的代码*/
    /*****BEGIN*****/
    int d = x % pt->n;
    HNode *temp;
    (*count)++;
    if (pt->pn[d].key == 0)
    {
        return false;
    }
    else if (pt->pn[d].key == x)
    {
        pt->pn[d].key = 0;
        if (pt->pn[d].next != NULL)
        {
            temp = pt->pn[d].next;
            pt->pn[d].key = pt->pn[d].next->key;
            pt->pn[d].next = pt->pn[d].next->next;
            free(temp);
        }
        return true;
    }

    HNode *pre = &(pt->pn[d]);
    while (pre->next != NULL)
    {
        (*count)++;
        if (pre->next->key == x)
        {
            temp = pre->next;
            pre->next = pre->next->next;
            free(temp);
            return true;
        }
        pre = pre->next;
    }

    return false;

    /******END******/
    /*请不要修改[BEGIN,END]区域外的代码*/
}

void ILH_Print(LHTable *pt)
{
    for (int i = 0; i < pt->n; i++)
    {
        printf("%5d:", i);
        if (pt->pn[i].key)
        {
            printf("%d", pt->pn[i].key);
            HNode *curr = pt->pn[i].next;
            while (curr)
            {
                printf("->%d", curr->key);
                curr = curr->next;
            }
            printf("\n");
        }
        else
            printf("-\n");
    }
}