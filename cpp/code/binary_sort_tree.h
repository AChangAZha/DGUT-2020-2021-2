//
//  binary_sort_tree.h
//  BinarySortTree
//
//  Created by ljpc on 2018/5/11.
//  Copyright ? 2018年 ljpc. All rights reserved.
//

#ifndef binary_sort_tree_h
#define binary_sort_tree_h

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct BiTreeNode
{
    int data;          //  树节点元素
    BiTreeNode *left;  //  左子树指针
    BiTreeNode *right; //  右子树指针
    BiTreeNode()
    { //  树节点初始化
        left = NULL;
        right = NULL;
    }
    BiTreeNode(int item)
    { //  用元素初始化树节点
        data = item;
        left = NULL;
        right = NULL;
    }
    ~BiTreeNode()
    { //  释放树节点内存
        left = NULL;
        right = NULL;
    }
};

int searchBiSortTree(BiTreeNode *root, int key, int *count)
// 功能：实现在升序二叉排序树中查找指定元素key
// 输入：待查找元素key
// 返回：比较次数*count；查找成功返回1，失败返回0
{
    // 请在这里补充代码
    /********** Begin *********/
    BiTreeNode *p;
    if (root != NULL)
    {
        p = root;
        while (p != NULL)
        {
            (*count)++;
            if (p->data == key)
                return 1;
            if (key > p->data)
                p = p->right;
            else
                p = p->left;
        }
    }
    return 0;

    /********** End **********/
}

BiTreeNode *insertBiSortTree(BiTreeNode *root, int key)
// 功能：实现向升序二叉排序树插入元素
// 输入：待插入元素key
// 返回：升序二叉排序树根节点
// 请在这里补充代码，完成本关任务
{
    // 请在这里补充代码
    /********** Begin *********/
    BiTreeNode *current, *parent = NULL;
    current = root;
    while (current != NULL)
    {
        if (current->data == key)
        {
            cout << "数据元素" << key << "存在，插入失败" << endl;
            return root;
        }
        parent = current;
        if (current->data < key)
            current = current->right;
        else
            current = current->left;
    }
    BiTreeNode *p = new BiTreeNode(key);
    if (parent == NULL)
        root = p;
    else if (key < parent->data)
        parent->left = p;
    else
        parent->right = p;
    cout << "数据元素" << key << "插入成功" << endl;
    return root;
    /********** End **********/
}

BiTreeNode *creatBiSortTree(int *arr, int n)
// 功能：实现创建升序二叉排序树
// 输入：无序整数数列arr，数列个数n
// 返回：升序二叉排序树根节点
{
    // 请在这里补充代码
    /********** Begin *********/
    BiTreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insertBiSortTree(root, arr[i]);
    }
    return root;
    /********** End **********/
}

#endif /* binary_sort_tree_h */
