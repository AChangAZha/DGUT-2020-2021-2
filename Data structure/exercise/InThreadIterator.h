typedef struct Node
{
    DataType data;
    int leftThread; //左线索标志位
    struct Node *leftChild;
    struct Node *rightChild;
    int rightThread; //右线索标志位
} ThreadBiNode;
typedef struct
{
    ThreadBiNode *root;
    ThreadBiNode *current;
    int nextComplete;
} ThreadBiTree;
void ThreadInitiate(ThreadBiTree *tree, ThreadBiNode *root)
{
    tree->root = root;
    tree->current = root;
    if (root == NULL)
        tree->nextComplete = 1;
    else
        tree->nextComplete = 0;
}
void First(ThreadBiTree *tree)
{
    tree->current = tree->root;
    while (tree->current->leftThread == 0)
    {
        tree->current = tree->current->leftChild;
    }
    if (tree->current == tree->root)
        tree->nextComplete = 1;
    else
        tree->nextComplete = 0;
}
void Next(ThreadBiTree *tree)
{
    ThreadBiNode *p = tree->current->rightChild;
    if (tree->nextComplete == 1)
        return;
    if (tree->current->rightThread == 0)
        while (p->leftThread == 0)
            p = p->leftChild;
    tree->current = p;
    if (tree->current == tree->root)
        tree->nextComplete = 1;
}
int EndOfNext(ThreadBiTree *tree)
{
    return tree->nextComplete;
}
void InThread(ThreadBiNode *current, ThreadBiNode **pre)
{
    if (current != NULL)
    {
        InThread(current->leftChild, pre);
        if (current->leftChild == NULL)
        {
            current->leftThread = 1;
            current->leftChild = *pre;
        }
        else
            current->leftThread = 0;
        if (current->rightChild != NULL)
            current->rightThread = 0;
        else
            current->rightThread = 1;
        if ((*pre)->rightChild == NULL)
        {
            (*pre)->rightThread = 1;
            (*pre)->rightChild = current;
        }
        else
            (*pre)->rightThread = 0;
        *pre = current;
        InThread(current->rightChild, pre);
    }
}
void CreatInThread(ThreadBiNode **root)
{
    ThreadBiNode *t = *root;
    ThreadBiNode *current, *pre;
    *root = (ThreadBiNode *)malloc(sizeof(ThreadBiNode));
    pre = *root;
    if (t == NULL)
    {
        (*root)->leftThread = 0;
        (*root)->rightThread = 1;
        (*root)->leftChild = *root;
        (*root)->rightChild = *root;
    }
    else
    {
        current = t;
        (*root)->leftChild = t;
        (*root)->leftThread = 0;
        InThread(current, &pre);
        pre->rightChild = *root;
        pre->rightThread = 1;
        (*root)->rightChild = pre;
        (*root)->rightThread = 1;
    }
}