// 有序数组转为二叉查找树-递归  l-108
// 符合条件的有很多，返回1棵即可
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 输入:{1,2,3,4,5}
   输出:{4,2,5,1,3}*/
// 把nums[left,right]区间转成BST
TreeNode* helper(vector<int>&nums,int left,int right)
{
    if (left>right) return nullptr;
    if (left==right) return new TreeNode(nums[left]);
    int mid=(left+right)/2; // 取中间偏左的数
    TreeNode* root=new TreeNode(nums[mid]);
    root->left=helper(nums,left,mid-1);
    root->right=helper(nums,mid+1,right);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>&nums)
{
    return helper(nums,0,nums.size()-1);
}