// unique binary search tree II - recursion  l-95
// return answer in any order
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode*>builtTree(int begin, int end)
{
    vector<TreeNode*> res;
    if (begin>end) 
    {
        res.emplace_back(nullptr);
        return res;
    }
    TreeNode *root;
    for (int i = begin; i <= end; i++)
    {
        vector<TreeNode*> left = builtTree(begin, i - 1);
        vector<TreeNode *> right = builtTree(i + 1, end);
        for (auto l:left)
        {
            for (auto r:right)
            {
                TreeNode* root=new TreeNode(i,l,r);
                res.emplace_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n)
{
    return builtTree(1,n);
}
