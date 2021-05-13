#include <stdlib.h>
#include <stdio.h>
typedef char DataType;
#include "BiTree.h"

int main()
{
    BiTreeNode *root, *p, *find;
    char x = 'E';
    Initiate(&root);
    p = InsertLeftNode(root, 'A');
    p = InsertLeftNode(p, 'B');
    p = InsertLeftNode(p, 'D');
    p = InsertRightNode(p, 'G');
    p = InsertRightNode(root->leftChild, 'C');
    InsertLeftNode(p, 'E');
    InsertRightNode(p, 'F');
    // DeleteLeftTree(root);
    PrintBiTree(root, 0);
    printf("前序遍历：");
    PreOrder(root->leftChild, Visit);
    printf("中序遍历：");
    InOrder(root->leftChild, Visit);
    printf("后序遍历：");
    PostOrder(root->leftChild, Visit);
    find = Search(root, x);
    if (find != NULL)
        printf("YES!\n");
    else
        printf("NO\n");
    Destroy(&root);
}