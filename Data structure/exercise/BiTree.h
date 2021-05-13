typedef struct Node
{
	DataType data;			 //数据域
	struct Node *leftChild;	 //左子树指针
	struct Node *rightChild; //右子树指针
} BiTreeNode;
void Initiate(BiTreeNode **root) //初始化建立二叉树的头结点
{
	*root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	(*root)->leftChild = NULL;
	(*root)->rightChild = NULL;
}
BiTreeNode *InsertLeftNode(BiTreeNode *curr, DataType x)
{
	BiTreeNode *s, *t;
	if (curr == NULL)
		return NULL;
	t = curr->leftChild; //保存原curr所指结点的左子树指针
	s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->leftChild = t; //新插入结点的左子树为原curr的左子树
	s->rightChild = NULL;
	curr->leftChild = s; //新结点为curr的左子树
	return curr->leftChild;
}
BiTreeNode *InsertRightNode(BiTreeNode *curr, DataType x)
{
	BiTreeNode *s, *t;
	if (curr == NULL)
		return NULL;
	t = curr->rightChild; //保存原curr所指结点的右子树指针
	s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->rightChild = t; //新插入结点的右子树为原curr的右子树
	s->leftChild = NULL;
	curr->rightChild = s; //新结点为curr的右子树
	return curr->rightChild;
}
void Destroy(BiTreeNode **root)
{
	if ((*root) != NULL)
	{
		Destroy(&(*root)->leftChild);
		Destroy(&(*root)->rightChild);
		free(*root);
	}
}
BiTreeNode *DeleteLeftTree(BiTreeNode *curr)
{
	if (curr == NULL || curr->leftChild == NULL)
		return NULL;
	Destroy(&curr->leftChild); //撤销操作
	curr->leftChild = NULL;
	return curr;
}
BiTreeNode *DeleteRightTree(BiTreeNode *curr)
{
	if (curr == NULL || curr->rightChild == NULL)
		return NULL;
	Destroy(&curr->rightChild); //撤销操作
	curr->rightChild = NULL;
	return curr;
}
void Visit(DataType item)
{
	printf("%c ", item);
}
void PreOrder(BiTreeNode *root, void Visit(DataType item))
{
	if (root != NULL)
	{
		Visit(root->data);
		PreOrder(root->leftChild, Visit);
		PreOrder(root->rightChild, Visit);
	}
}
void InOrder(BiTreeNode *root, void Visit(DataType item))
{
	if (root != NULL)
	{
		InOrder(root->leftChild, Visit);
		Visit(root->data);
		InOrder(root->rightChild, Visit);
	}
}
void PostOrder(BiTreeNode *root, void Visit(DataType item))
{
	if (root != NULL)
	{
		PostOrder(root->leftChild, Visit);
		PostOrder(root->rightChild, Visit);
		Visit(root->data);
	}
}
void PrintBiTree(BiTreeNode *root, int n)
{
	int i;
	if (root == NULL)
		return;
	PrintBiTree(root->rightChild, n + 1);
	for (i = 0; i < n - 1; i++)
		printf("   ");
	if (n > 0)
	{
		printf("---");
		printf("%c\n", root->data);
	}
	PrintBiTree(root->leftChild, n + 1);
}
BiTreeNode *Search(BiTreeNode *root, DataType x)
{
	BiTreeNode *find = NULL;
	if (root != NULL)
	{
		if (root->data == x)
			find = root;
		else
		{
			find = Search(root->leftChild, x);
			if (find == NULL)
				find = Search(root->rightChild, x);
		}
	}
	return find;
}
void CreateBiTree(BiTreeNode **root, FILE *fp)
{
	DataType ch;
	fscanf(fp, "%c", &ch);
	if (ch == '^')
	{
		*root = NULL;
		return;
	}
	*root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	(*root)->data = ch;
	CreateBiTree(&(*root)->leftChild, fp);
	CreateBiTree(&(*root)->rightChild, fp);
}