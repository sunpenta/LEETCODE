// 二叉树的路径之和-递归  l-113  -dfs/vector/2.1
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
// test-condition:targetSum-root->val==0
void dfs(vector<vector<int>>&paths,vector<int>&path,TreeNode* root,int targetSum)
{
    if (!root) return; 
    path.emplace_back(root->val); // path is here
    targetSum-=root->val;
    if (!root->left && !root->right && targetSum==root->val) // leaf
    {
        paths.emplace_back(path); // *无 return*
    }
    dfs(paths,path,root->left,targetSum);
    dfs(paths,path,root->right,targetSum);
    path.pop_back();
}
/*输入:root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
  输出:{{5,4,11,2},{5,8,4,5}}*/
vector<vector<int>>pathSum(TreeNode*root,int targetSum)
{
    vector<vector<int>>paths; vector<int>path;
    dfs(paths,path,root,targetSum);
    return paths;
}

