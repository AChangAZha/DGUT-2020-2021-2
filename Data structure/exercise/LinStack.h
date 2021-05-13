/* 链式堆栈 */
typedef struct snode
{
    DataType data;
    struct snode *next;
} LSNode;
void StackInitiate(LSNode **head)
{
    *head = (LSNode *)malloc(sizeof(LSNode));
    (*head)->next = NULL;
}
int StackNotEmpty(LSNode *head)
{
    if (head->next == NULL)
        return 0;
    else
        return 1;
}
void StackPush(LSNode *head, DataType x)
{
    LSNode *p;
    p = (LSNode *)malloc(sizeof(LSNode));
    p->data = x;
    p->next = head->next;
    head->next = p;
}
int StackPop(LSNode *head, DataType *d)
{
    LSNode *p = head->next;
    if (p == NULL)
    {
        printf("堆栈已空出错！");
        return 0;
    }
    head->next = p->next;
    *d = p->data;
    free(p);
    return 1;
}
int StackTop(LSNode *head, DataType *d)
{
    LSNode *p = head->next;
    if (p == NULL)
    {
        printf("堆栈已空出错！");
        return 0;
    }
    *d = p->data;
    return 1;
}
void Destroy(LSNode *head)
{
    LSNode *p, *p1;
    p = head;
    while (p != NULL)
    {
        p1 = p;
        p = p->next;
        free(p1);
    }
}