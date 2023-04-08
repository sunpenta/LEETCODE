// 二叉树的前序遍历
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
   输出:{3,9,20,15,7}*/                     //        9     20
vector<int>res;                            //             15  7
vector<int>preorderTraversal(TreeNode* root)
{
    if (root)
    {
        res.emplace_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    return res;  
}
// 迭代
vector<int>preorderTraversal(TreeNode* root)
{
    vector<int>res;
    stack<TreeNode*>sk;
    TreeNode* rt=root;
    while (rt || !sk.empty())
    {
        while (rt)
        {
            res.emplace_back(rt->val);
            sk.emplace(rt);
            rt=rt->left;
        }
        rt=sk.top();
        sk.pop();
        rt=rt->right;
    }
    return res;
}