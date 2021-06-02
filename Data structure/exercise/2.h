/* 二叉树头文件 */
typedef struct Node //结点
{
    ElemType data;           //数据域
    struct Node *leftChild;  //左子树指针
    struct Node *rightChild; //右子树指针
} BiTreeNode;
typedef BiTreeNode *DataType; //堆栈、队列的元素为结点

#include "SeqCQueue.h" //队列头文件
#include "SeqStack.h"  //堆栈头文件

//1.通过文件读取方式，建立二叉树
void CreateBiTree(BiTreeNode **root, FILE *fp)
{
    char ch;
    fscanf(fp, "%c", &ch);
    if (ch == '^') //遇到^说明为空结点
    {
        *root = NULL;
        return;
    }
    *root = (BiTreeNode *)malloc(sizeof(BiTreeNode)); //创建新结点
    (*root)->data = ch;
    CreateBiTree(&(*root)->leftChild, fp);  //创建当前结点的左子树
    CreateBiTree(&(*root)->rightChild, fp); //创建当前结点的右子树
}

//输出结点
void Visit(ElemType item)
{
    printf("%c ", item);
}

//2.非递归方式先序遍历
void PreOrder(BiTreeNode *root, void Visit(ElemType item))
{
    BiTreeNode *p;
    SeqStack stack;
    StackInitiate(&stack); //堆栈初始化
    p = root;
    if (p == NULL)
        printf("二叉树为空！\n");
    else
    {
        StackPush(&stack, p); //根结点入栈
        do
        {
            StackPop(&stack, &p); //结点出栈
            Visit(p->data);       //输出结点
            if (p->rightChild != NULL)
                StackPush(&stack, p->rightChild); //当前结点的右孩子入栈
            if (p->leftChild != NULL)
                StackPush(&stack, p->leftChild); //当前结点的左孩子入栈
        } while (StackNotEmpty(stack));          //当堆栈为空时结束循环
    }
}

//3.非递归方式中序遍历
void InOrder(BiTreeNode *root, void Vist(ElemType item))
{
    BiTreeNode *p;
    SeqStack stack;
    StackInitiate(&stack); //堆栈初始化
    p = root;
    if (p == NULL)
        printf("二叉树为空！\n");
    while (p || StackNotEmpty(stack)) //堆栈为空时结束循环
    {
        if (p)
        {
            StackPush(&stack, p); //结点入栈
            p = p->leftChild;     //指向左子树
        }
        else //左子树为空后
        {
            StackPop(&stack, &p); //退栈
            Visit(p->data);       //访问结点。
            p = p->rightChild;    //指向右子树
        }
    }
}

//4.后序遍历
void PostOrder(BiTreeNode *root, void Visit(ElemType item))
{
    if (root != NULL)
    {
        PostOrder(root->leftChild, Visit);
        PostOrder(root->rightChild, Visit);
        Visit(root->data);
    }
}

//5.层序遍历
void LevelOrder(BiTreeNode *root, void Visit(ElemType item))
{
    BiTreeNode *p;
    SeqCQueue queue;
    QueueInitiate(&queue); //队列初始化
    p = root;
    if (p == NULL)
        printf("二叉树为空！\n");
    else
    {
        QueueAppend(&queue, p);      //根结点入列
        while (QueueNotEmpty(queue)) //当队列为空时循环结束
        {
            QueueDelete(&queue, &p); //结点出列
            Visit(p->data);          //输出结点
            if (p->leftChild != NULL)
                QueueAppend(&queue, p->leftChild); //当前结点的左孩子入列
            if (p->rightChild != NULL)
                QueueAppend(&queue, p->rightChild); //当前结点的右孩子入列
        }
    }
}

//6.计算树T的深度
int TreeDepth(BiTreeNode *root)
{
    int leftDepth = -1; //深度初始化为-1
    int rightDepth = -1;
    if (root == NULL)
        return -1; //若为空结点，则深度为-1
    else
    {
        leftDepth = TreeDepth(root->leftChild);   //计算左子树深度
        rightDepth = TreeDepth(root->rightChild); //计算右子树深度
        //二叉树的深度为其左右子树的深度较大值加1
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}

//6.输出树T的叶子结点
void PrintLeaf(BiTreeNode *root)
{
    if (root != NULL)
    {
        //采用前序遍历
        if (root->leftChild == NULL && root->rightChild == NULL) //无左孩子和右孩子
            Visit(root->data);
        PrintLeaf(root->leftChild);
        PrintLeaf(root->rightChild);
    }
}

//6.输出树T的非叶子结点
void PrintNotLeaf(BiTreeNode *root)
{
    //采用前序遍历
    if (root != NULL)
    {
        if (root->leftChild != NULL || root->rightChild != NULL) //存在左孩子或右孩子
            Visit(root->data);
        PrintNotLeaf(root->leftChild);
        PrintNotLeaf(root->rightChild);
    }
}

//选做1.判断该二叉树是否为完全二叉树
int ComBiTree(BiTreeNode *root) //函数返回1说明该二叉树为完全二叉树
{
    int flag = 0; //当flag为1时表示已遇到空结点
    BiTreeNode *p;
    SeqCQueue queue;
    QueueInitiate(&queue); //队列初始化
    p = root;
    if (p == NULL)
    {
        printf("二叉树为空！\n");
        return 0;
    }
    else
    {
        QueueAppend(&queue, p);      //根结点入列
        while (QueueNotEmpty(queue)) //当队列为空时结束循环
        {
            QueueDelete(&queue, &p); //结点出列
            if (p->leftChild != NULL)
            {
                //遍历过程中若遇到空结点后仍有非空结点入列，则说明该二叉树不是完全二叉树
                if (flag == 1)
                    return 0;
                QueueAppend(&queue, p->leftChild); //当前结点的左孩子入列
            }
            else
                flag = 1; //若遇到空结点，flag的值由0变为1
            if (p->rightChild != NULL)
            {
                if (flag == 1)
                    return 0;
                QueueAppend(&queue, p->rightChild); //当前结点的右孩子入列
            }
            else
                flag = 1;
        }
    }
    return 1; //若完成上述循环，说明该二叉树为完全二叉树
}

//选做2.根据顺序存储建立二叉链存储的二叉树
void CreateBiTree2(BiTreeNode **root, ElemType BT[], int n)
{
    //访问BT[n]
    if (n > strlen(BT) - 1 || BT[n] == '^') //当n超过数组长度或数组元素为^时，返回
    {
        *root = NULL;
        return;
    }
    *root = (BiTreeNode *)malloc(sizeof(BiTreeNode)); //创建新节点
    (*root)->data = BT[n];
    CreateBiTree2(&(*root)->leftChild, BT, 2 * n + 1);  //访问BT[2n+1]，创建左孩子
    CreateBiTree2(&(*root)->rightChild, BT, 2 * n + 2); //访问BT[2n+2]，创建右孩子
}

//撤销二叉树
void Destroy(BiTreeNode **root)
{
    if ((*root) != NULL)
    {
        Destroy(&(*root)->leftChild);
        Destroy(&(*root)->rightChild);
        free(*root);
    }
}

int leaf(BiTreeNode *T)
{
    if (T == NULL)
        return 0;
    else if (T->leftChild == NULL && T->rightChild == NULL)
        return 1;
    else
        return leaf(T->leftChild) + leaf(T->rightChild);
}

int leaf_2(BiTreeNode *T)
{
    int leaf = 0;
    BiTreeNode *p;
    SeqStack stack;
    StackInitiate(&stack); //堆栈初始化
    p = T;
    if (p == NULL)
        printf("二叉树为空！\n");
    else
    {
        StackPush(&stack, p); //根结点入栈
        do
        {
            StackPop(&stack, &p); //结点出栈
            if (p->leftChild == NULL && p->rightChild == NULL)
                leaf++;
            if (p->rightChild != NULL)
                StackPush(&stack, p->rightChild); //当前结点的右孩子入栈
            if (p->leftChild != NULL)
                StackPush(&stack, p->leftChild); //当前结点的左孩子入栈
        } while (StackNotEmpty(stack));          //当堆栈为空时结束循环
    }
    return leaf;
}
