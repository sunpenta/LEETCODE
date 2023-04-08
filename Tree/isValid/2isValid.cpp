// 二叉查找树-递归  l-98
// 左子树小于当前根节点；右子树大于当前根节点；所有左子树和右子树都是BST;-2e31<=Node.val<=2e31-1
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool isValid(TreeNode* root,long lower,long upper) // *long*
{
    if (!root) // 终止条件
        return true;
    if (root->val<=lower || root->val>=upper)   
        return false;
    return isValid(root->left,lower,root->val) 
        && isValid(root->right,root->val,upper); // &&
}

bool isValidBST(TreeNode* root)
{
    return isValid(root,LONG_MIN,LONG_MAX);
}