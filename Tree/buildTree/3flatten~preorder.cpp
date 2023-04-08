// 二叉树展开成链表形式-前序遍历 l-114
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
// 前序遍历
void preorder(TreeNode* root,vector<int>&nums)
{
    if (root)
    {
        nums.emplace_back(root->val);
        preorder(root->left,nums);
        preorder(root->right,nums);
    }
}

void flatten(TreeNode* root)
{
    if (!root) return;
    vector<int>nums;
    preorder(root,nums);
    TreeNode* res=root;
    for (int i=0;i<nums.size();i++)
    {
        res->val=nums[i];
        res->left=nullptr;
        res->right=new TreeNode();
        res=res->right;
    }
}

