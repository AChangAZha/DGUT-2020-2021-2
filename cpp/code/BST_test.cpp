//
//  BST_test.cpp
//  BinarySortTree
//

#include "binary_sort_tree.h"

int *InOrder(BiTreeNode *root, int *arr, int &i);
// 功能：实现升序二叉排序树的中序遍历
// 参数：二叉树根节点root，整数数列arr，起始下标i=0
// 返回：中序遍历数列arr

int main(int argc, const char *argv[])
{
    // insert code here...

    int n;
    int arr[100];
    printf("请输入数据个数：\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    //可以通过菜单选择测试输出、查找、插入和删除
    /*请在BEGIN和END之间实现你的代码*/
    /*****BEGIN*****/
    cout << "\n建立BST树：" << endl;
    BiTreeNode *root = creatBiSortTree(arr, n);
    cout << "\n查找：";
    int key, count = 0;
    cin >> key;
    if (searchBiSortTree(root, key, &count))
        cout << "数据元素" << key << "存在";
    else
        cout << "数据元素" << key << "不存在";
    cout << "，比较次数：" << count << endl;
    cout << "\n插入：";
    cin >> key;
    root = insertBiSortTree(root, key);
    cout << "\n按中序遍历输出：";
    int m = 0;
    int *arr2 = InOrder(root, arr, m);
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    /******END******/
    system("pause");
    return 0;
}

int *InOrder(BiTreeNode *root, int *arr, int &i)
// 功能：实现升序二叉排序树的中序遍历
// 参数：二叉树根节点root，整数数列arr，起始下标i=0
// 返回：中序遍历数列arr
{
    if (root == NULL)
    {
        return arr;
    }
    InOrder(root->left, arr, i);
    arr[i++] = root->data;
    InOrder(root->right, arr, i);
    return arr;
}