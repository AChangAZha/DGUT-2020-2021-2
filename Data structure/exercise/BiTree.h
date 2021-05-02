typedef char DataType;
typedef struct Node 
{
    DataType data;			//数据域
	struct Node *leftChild;		//左子树指针
	struct Node *rightChild;      	//右子树指针
}BiTreeNode;
void Initiate(BiTreeNode **root)  //初始化建立二叉树的头结点
{
	*root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	(*root)->leftChild = NULL;
	(*root)->rightChild = NULL;
}
BiTreeNode *InsertLeftNode(BiTreeNode *curr, DataType x)
{
	BiTreeNode *s, *t;
 	if(curr == NULL) return NULL;
	t = curr->leftChild; 	//保存原curr所指结点的左子树指针
	s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->leftChild = t;   	//新插入结点的左子树为原curr的左子树
	s->rightChild = NULL;
 	curr->leftChild = s;  	//新结点为curr的左子树
	return curr->leftChild;	
}
BiTreeNode *InsertRightNode(BiTreeNode *curr, DataType x)
{
	BiTreeNode *s, *t;
 	if(curr == NULL) return NULL;
	t = curr->rightChild;      	//保存原curr所指结点的右子树指针
	s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->rightChild = t;   	//新插入结点的右子树为原curr的右子树
	s->leftChild = NULL;
 	curr->rightChild = s;  	//新结点为curr的右子树
	return curr->rightChild;	
}
BiTreeNode *DeleteLeftTree(BiTreeNode *curr)
{
	if(curr == NULL || curr->leftChild == NULL) return NULL;
	Destroy(&curr->leftChild); //撤销操作
	curr->leftChild = NULL;
	return curr;
}
BiTreeNode *DeleteRightTree(BiTreeNode *curr)
{
	if(curr == NULL || curr->rightChild == NULL) return NULL;
 	Destroy(&curr->rightChild); //撤销操作
	curr->rightChild = NULL;
	return curr;
}
void visit(DataType item)
{
	printf("%c ", item);
}
void PreOrder(BiTreeNode *root, void visit(DataType item))
 {
	if(root!=NULL)
	{
		visit(root->data);
		PreOrder(root->leftChild, visit);
		PreOrder(root->rightChild, visit);
	}
}
void InOrder(BiTreeNode *root, void visit(DataType item))
{
	if(root != NULL)
	{	
        InOrder(root->leftChild, visit);
		visit(root->data);
		InOrder(root->rightChild, visit);
	}
}
void PostOrder(BiTreeNode *root, void visit(DataType item))
/*后序遍历二叉树t */
{
	if(root != NULL)
	{	
        PostOrder(root->leftChild, visit);
		PostOrder(root->rightChild, visit);
		Visit(root->data);
	}
}
