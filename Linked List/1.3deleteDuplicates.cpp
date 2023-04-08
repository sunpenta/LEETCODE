// 删除链表重复元素 l-83
// 长度[0, 300]; -100 <= Node.val <= 100 链表按升序排列
#include <bits/stdc++.h>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*  输入：head = [1,1,2,3,3]
    输出：       [2] */
ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* dummy=new ListNode(INT_MAX,head); // 在头节点前新建哑节点
    ListNode* cur=dummy;
    while (cur->next!=nullptr && cur->next->next!=nullptr)
    {
        if (cur->next->val==cur->next->next->val)
        {
            int tmp=cur->next->val;
            while (cur->next!=nullptr && cur->next->val==tmp)
                cur->next=cur->next->next; // 1个不留
        }
        else
        {
            cur=cur->next;
        }
    }
    ListNode* ans=dummy->next;
    delete dummy;
    return ans;
}