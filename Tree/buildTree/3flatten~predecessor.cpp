// ������չ����������ʽ-��ǰ���ڵ�   l-114
// չ��˳����ǰ�������ͬ��������Ϊ�գ�rightָ����һ�ڵ�
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};
/* ����:root = [1,2,5,3,4,null,6]
   ���:[1,null,2,null,3,null,4,null,5,null,6]*/
// ��ǰ���ڵ�
void* flatten(TreeNode* root)
{
    if (!root) return nullptr;
    TreeNode* cur=root;
    while (cur)
    {
        if (cur->left)
        {
            TreeNode* next=cur->left;
            TreeNode* predecessor=next;
            while (predecessor->right)
            {
                predecessor=predecessor->right;
            }
            predecessor=cur->right;
            cur->left=nullptr;
            cur->right=next;
        }
        cur=cur->right;
    }
}