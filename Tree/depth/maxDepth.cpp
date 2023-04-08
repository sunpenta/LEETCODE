// 二叉树的最大深度-dfs  l-104
#include <bits/stdc++.h>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

int maxDepth(TreeNode* root)
{
    if (!root) return 0;
    return max(maxdpth(root->left),maxdepth(root->right))+1;
}