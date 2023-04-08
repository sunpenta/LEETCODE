// 平衡二叉树-递归  l-110
// 左右子树的高度差的绝对值不超过1
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 1.top-down
int height_td(TreeNode* root) // 深度
{
    if (!root) return 0;
    return max(height_td(root->left),height_td(root->right))+1;
}

bool isBalanced_td(TreeNode* root)
{
    if (!root) return true;
    if (abs(height_td(root->left)-height_td(root->right))>1)
        return false;
    return isBalanced_td(root->left) && isBalanced_td(root->right);
}

// 2.down-top
int height_dt(TreeNode* root)
{
    if (!root) return 0;
    int lheight=height_dt(root->left), rheight=height_dt(root->right);
    if (lheight==-1 || rheight==-1 || abs(lheight-rheight)>1)
        return -1;
    else
        return max(height_dt(root->left),height_dt(root->right))+1; 
}

bool isBalanced_dt(TreeNode* root)
{
    return height_dt(root)!=-1;
}