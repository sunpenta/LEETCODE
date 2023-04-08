// 二叉树的层序遍历-bfs  l-102
#include <bits/stdc++.h>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

/* 输入:root = [3,9,20,null,null,15,7]                   3
   输出:{{3},{9,20},{15,7}}*/                   //    9     20
vector<vector<int>>levelOrder(TreeNode* root)  //         15  7    
{
   vector<vector<int>>res;
   // 特殊情况:二叉树为空
   if (!root) return res;

   queue<TreeNode*>q;
   q.emplace(root);
   while (!q.empty())
   {
        int levelSize=q.size(); // 当前层的元素数
        res.emplace_back(vector<int>(levelSize));
        for (int i=0;i<levelSize;i++) 
        {
            TreeNode *rt=q.front();
            q.pop();
            res.back()[i]=rt->val;
            if (rt->left) q.emplace(rt->left); // *无!*
            if (rt->right) q.emplace(rt->right);
        }
   }
   // reverse(res.begin(),res.end()); down-top层序遍历
   return res;
}