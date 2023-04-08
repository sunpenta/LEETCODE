// 相同的树-递归  l-100
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool isSameTree(TreeNode* p,TreeNode* q)
{
    if (!p && !q) return true;
    else if (!p || !q) return false;
    else
        return p->val==q->val && isSameTree(p->left,q->left) 
        && isSameTree(p->right,q->right);
}
