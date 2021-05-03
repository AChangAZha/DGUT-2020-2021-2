#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
typedef struct Node 
{
    DataType data;			//数据域
	struct Node *leftChild;		//左子树指针
	struct Node *rightChild;      	//右子树指针
}BiTreeNode;
void CreateBiTree(BiTreeNode **root,FILE *fp)
{
	DataType ch;
	fscanf(fp,"%c",&ch);
	if(ch=='*')
	{
		*root=NULL;
		return;
	}
	*root=(BiTreeNode*)malloc(sizeof(BiTreeNode));
	(*root)->data=ch;
	CreateBiTree(&(*root)->leftChild,fp);
	CreateBiTree(&(*root)->rightChild,fp);
}
int main()
{
    BiTreeNode *root;
    FILE *fp;
    fp=fopen("BiTree.txt","r");
    CreateBiTree(&root,fp);
}