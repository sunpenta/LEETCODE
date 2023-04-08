// 恢复二叉搜索树-显式中序遍历  l-99
// 树中两个节点的值被错误交换
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

/* 输入:root = [1,3,null,null,2]
   输出:[3,1,null,null,2]*/
// 中序遍历
void inorder(TreeNode* root,vector<int>&nums)
{
    if (!root) return;
    inorder(root->left,nums);
    nums.emplace_back(root->val);
    inorder(root->right,nums);
}
// 找到错误交换的两个元素
pair<int,int> findTwoNums(vector<int>&nums)
{
    int index1=-1,index2=-1;
    for (int i=1;i<nums.size();i++)
    {
        if (nums[i]<nums[i-1])
        {
            index2=i;
            if (index1==-1) index1=i-1;
            else break;
        }      
    }
    return {nums[index1],nums[index2]};
}
// 恢复BST
void recover(TreeNode* root,int count,int x,int y)
{
    if (root)
    {
        if (root->val==x || root->val==y)
        {
            root->val=(root->val==x)?y:x; // 换成另一个元素
            if (--count==0) return;
        }
        recover(root->left,count,x,y);
        recover(root->right,count,x,y);     
    } 
}
void recoverTree(TreeNode* root)
{
    vector<int>nums;
    inorder(root,nums); // 中序遍历
    pair<int,int>swapped=findTwoNums(nums); // 找到两个错误交换的元素
    return recover(root,2,swapped.first,swapped.second); // 恢复BST
}