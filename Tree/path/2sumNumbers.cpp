// 从根节点到叶子节点数字和-递归  l-129
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
int sumNumbers(TreeNode* root);

int dfs(TreeNode* root,int presum)
{
    if (!root) return 0;
    int sum=10*presum+root->val;
    if (!root->left && !root->right)
        return sum;
    else
        return dfs(root->left,sum)+dfs(root->right,sum);
}
int sumNumbers(TreeNode* root)
{
    return dfs(root,0);
}