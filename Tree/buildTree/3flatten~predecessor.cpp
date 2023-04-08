// 二叉树展开成链表形式-找前驱节点   l-114
// 展开顺序与前序遍历相同；左子树为空，right指向下一节点
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};
/* 输入:root = [1,2,5,3,4,null,6]
   输出:[1,null,2,null,3,null,4,null,5,null,6]*/
// 找前驱节点
void* flatten(TreeNode* root)
{
    if (!root) return nullptr;
    TreeNode* cur=root;
    while (cur)
    {
        if (cur->left)
        {
            TreeNode* next=cur->left;
            TreeNode* predecessor=next;
            while (predecessor->right)
            {
                predecessor=predecessor->right;
            }
            predecessor=cur->right;
            cur->left=nullptr;
            cur->right=next;
        }
        cur=cur->right;
    }
}