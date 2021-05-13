#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
#include "InThreadIterator.h"
ThreadBiNode *GetTreeNode(DataType item, ThreadBiNode *left, ThreadBiNode *right)
{
    ThreadBiNode *p;
    p = (ThreadBiNode *)malloc(sizeof(ThreadBiNode));
    p->data = item;
    p->leftChild = left;
    p->rightChild = right;
    return p;
}
void MakeCharTree(ThreadBiNode **root)
{
    ThreadBiNode *b, *c, *d, *e, *f, *g;
    g = GetTreeNode('G', NULL, NULL);
    d = GetTreeNode('D', NULL, g);
    b = GetTreeNode('B', d, NULL);
    e = GetTreeNode('E', NULL, NULL);
    f = GetTreeNode('F', NULL, NULL);
    c = GetTreeNode('C', e, f);
    *root = GetTreeNode('A', b, c);
}
int main()
{
    ThreadBiNode *root;
    ThreadBiTree tree;
    MakeCharTree(&root);
    CreatInThread(&root);
    ThreadInitiate(&tree, root);
    for (First(&tree); !EndOfNext(&tree); Next(&tree))
        printf("%c ", tree.current->data);
}