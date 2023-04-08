// 二叉树的Z字形层序遍历 -bfs  l-103
#include <bits/stdc++.h>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

/* 输入:root = [3,9,20,null,null,15,7]                       3
   输出:{{3},{20,9},{15,7}}*/                       //    9     20   
vector<vector<int>>zigzagLevelOrder(TreeNode* root)//         15  7
{
    vector<vector<int>>res;
    // 二叉树为空
    if (!root) return res;
    queue<TreeNode*>q;
    q.emplace(root);
    int flag=true;
    while (!q.empty())
    {
        int levelSize=q.size();
        res.emplace_back(vector<int>(levelSize));
        for (int i=0;i<levelSize;i++)
        {
            TreeNode* rt=q.front();
            q.pop();
            res.back()[flag?i:levelSize-i-1]=rt->val; // 实现正插和反插
            if (rt->left) q.emplace(rt->left);
            if (rt->right) q.emplace(rt->right);
        }
        flag=!flag; // falg取反
    }
    return res;
}