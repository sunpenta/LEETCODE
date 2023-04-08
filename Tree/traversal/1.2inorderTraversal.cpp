// 二叉树的中序遍历
#include <bits/stdc++.h>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
// 递归
/* 输入:root = [3,9,20,null,null,15,7]                   3
   输出:{9,3,15,20,7}*/                     //        9     20
vector<int>res;                            //             15  7
vector<int>inorderTraversal(TreeNode* root)
{
    if (root)
    {
        inorderTraversal(root->left);
        res.emplace_back(root->val);
        inorderTraversal(root->right);
    }
    return res;
}
// 迭代
vector<int>inorderTraversal(TreeNode* root)
{
    vector<int>res;
    stack<TreeNode*>sk;
    TreeNode* rt=root;
    while (rt || !sk.empty())
    {
        while (rt)
        {
            sk.emplace(rt);
            rt=rt->left;
        }
        rt=sk.top();
        sk.pop();
        res.emplace_back(rt->val);
        rt=rt->right;
    }
    return res;
}