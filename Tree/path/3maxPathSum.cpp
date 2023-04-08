// 最大路径和-递归  l-124
// node->val∈[-1000,1000]
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
// 节点root的最大贡献值
int maxGain(TreeNode* root)
{
    if (!root) return 0;
    int leftGain=max(0,maxGain(root->left)); // 子节点为负，不计入路径和
    int rightGain=max(0,maxGain(root->right));
    int sum=root->val+leftGain+rightGain;
    maxSum=max(maxSum,sum);
    return root->val+max(leftGain,rightGain);
}
int maxSum=INT_MIN; // 全局
int maxPathSum(TreeNode* root)
{
    maxGain(root);
    return maxSum;
}