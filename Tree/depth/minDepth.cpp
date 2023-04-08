// 二叉树的最小深度-bfs  l-111
#include <bits/stdc++.h>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

int minDepth(TreeNode* root)
{
    if (!root) return 0;
    queue<pair<TreeNode*,int>>q;
    q.emplace(root,1);
    while (!q.empty())
    {
        TreeNode* rt=q.front().first;
        int depth=q.front().second;
        q.pop();
        if (!rt->left && !rt->right) return depth;
        if (rt->left) q.emplace(rt->left,depth+1);
        if (rt->right) q.emplace(rt->right,depth+1);
    }
    return 0;
}