// 二叉树的路径之和-递归  l-112
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
/* 输入:root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
   输出：true  {5,4,11,2}*/
// test-condition:targetSum-root->val==0
bool hasPathSum(TreeNode* root,int targetSum)
{
    if (!root) return false;
    if (!root->left && !root->right && root->val==targetSum) // leaf
        return true;
    return hasPathSum(root->left,targetSum-root->val)
    || hasPathSum(root->right,targetSum-root->val);
}