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

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* dummy=new ListNode(INT_MAX,head); // 在头节点前新建哑节点，值在[-100,100]之外
    ListNode* cur=dummy;
    while (cur!=nullptr && cur->next!=nullptr)
    {
        if (cur->val==cur->next->val)
        {
            cur->next=cur->next->next; // 保留1个
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