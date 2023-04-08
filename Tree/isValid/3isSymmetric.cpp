// 对称二叉树-递归  l-101
// 以根节点为中心镜像对称
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool check(TreeNode* p,TreeNode* q)
{
    if (!p && !q) return true;
    else if (!p || !q) return false;
    else
        return p->val==q->val && check(p->left,q->right) && check(p->right,q->left);
}

bool isSymmetric(TreeNode* root)
{
    if (!root) return true;
    return check(root->left,root->right);
}