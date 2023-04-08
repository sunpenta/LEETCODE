// 有序链表转为二叉查找树-递归  l-109
// 符合条件的数很多,只需输出1棵即可
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
struct ListNode {
    int val;
    ListNode *next;
};

/* 输入:{1,2,3,4,5}
   输出:{4,2,5,1,3}*/
// 1.断开链接
TreeNode* sortedListToBST(ListNode* head)
{
    if (!head) return nullptr;
    if (!head->next) return new TreeNode(head->val); // 必须有
    TreeNode* root=new TreeNode();
    ListNode* slow=head, *fast=head, *preslow=nullptr;
    while (fast && fast->next)
    {
        preslow=slow;
        fast=fast->next->next;
        slow=slow->next; // 中间节点
    }
    root->val=slow->val;
    root->right=sortedListToBST(slow->next);
    preslow->next=nullptr; // 断开连接;
    root->left=sortedListToBST(head);
    return root;
}

// 2.不断开连接
TreeNode* helper(ListNode* head,ListNode* tail) // [head,tail)
{
    if (head==tail) return nullptr;
    ListNode* slow=head, *fast=head;
    while (fast!=tail && fast->next!=tail)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    TreeNode* root=new TreeNode(slow->val);
    root->left=helper(head,slow);
    root->right=helper(slow->next,tail);
    return root;
}

TreeNode* sortedListToBST(ListNode* head)
{
    return helper(head,nullptr);
}