// 二叉树的后序遍历
#include <bits/stdc++.h>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
/* 输入:root = [3,9,20,null,null,15,7]                   3
   输出:{9,15,7,20,3}*/                     //        9     20
// 递归                                     //             15  7
vector<int>res;
vector<int>postorderTraversal(TreeNode* root)
{
    if (root)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.emplace_back(root->val);
    }
    return res;
}
// 迭代
vector<int>postorderTraversal(TreeNode* root)
{
    vector<int>res;
    stack<TreeNode*>sk;
    TreeNode* rt=root, *prev=nullptr;
    while (rt || !sk.empty())
    {
        while (rt)
        {
            sk.emplace(rt);
            rt=rt->left;
        }
        rt=sk.top();
        sk.pop();
        if (rt->right && rt->right!=prev)
        {
            sk.emplace(rt); 
            rt=rt->right; 
        }
        else                                //     o rt
        {                                   //        o prev
            res.emplace_back(rt->val);      //      o   nullptr
            prev=rt;
            rt=nullptr;
        }
    }
    return res;
}