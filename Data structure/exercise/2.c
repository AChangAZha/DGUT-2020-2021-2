#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxQueueSize 100
#define MaxStackSize 100
typedef char ElemType;
#include "2.h"

int main()
{
    BiTreeNode *T;
    FILE *fp;
    char BT[]="ABCD^EFGH^^I^JK";
    int depth;
    
    //1.通过文件读取创建
    // fp=fopen("BiTree.txt","r");
    // CreateBiTree(&T,fp);
    // fclose(fp);

    //选做2.通过BT[n]创建
    CreateBiTree2(&T,BT,0);
    
    //2.非递归方式先序遍历
    printf("先序遍历：");
    PreOrder(T,Visit);
    printf("\n");

    //3.非递归方式中序遍历
    printf("中序遍历：");
    InOrder(T,Visit);
    printf("\n");

    //4.后序遍历
    printf("后序遍历：");
    PostOrder(T,Visit);
    printf("\n");

    //5.层序遍历
    printf("层序遍历：");
    LevelOrder(T,Visit);
    printf("\n");

    //6.输出树T的深度
    printf("树T的深度：%d\n",TreeDepth(T));

    //6.输出树T的叶子结点
    printf("树T的叶子结点：");
    PrintLeaf(T);
    printf("\n");

    //6.输出树T的非叶子结点
    printf("树T的非叶子结点：");
    PrintNotLeaf(T);
    printf("\n");

    //选做1.判断该二叉树是否为完全二叉树
    if(ComBiTree(T)) printf("该二叉树是完全二叉树\n");
    else printf("该二叉树不是完全二叉树\n");

    //撤销二叉树
    Destroy(&T);
    system("pause");
}