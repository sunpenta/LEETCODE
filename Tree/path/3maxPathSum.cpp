// ���·����-�ݹ�  l-124
// node->val��[-1000,1000]
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
// �ڵ�root�������ֵ
int maxGain(TreeNode* root)
{
    if (!root) return 0;
    int leftGain=max(0,maxGain(root->left)); // �ӽڵ�Ϊ����������·����
    int rightGain=max(0,maxGain(root->right));
    int sum=root->val+leftGain+rightGain;
    maxSum=max(maxSum,sum);
    return root->val+max(leftGain,rightGain);
}
int maxSum=INT_MIN; // ȫ��
int maxPathSum(TreeNode* root)
{
    maxGain(root);
    return maxSum;
}