// 删除链表重复元素 l-83
// 删除所有重复元素；length∈[0, 300]，链表按升序排列, Node.val∈[-100,100]
#include "ListNode.h"
using namespace std;
ListNode* deleteDuplicates(ListNode* head);

int main()
{
    vector<int> nums={1,1,2,3,3};
    ListNode* head=ListNode::vectorToListNode(nums);
    ListNode* res=deleteDuplicates(head);
    res->print(); // output: 2
    return 0;
}

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* dummy=new ListNode(101,head); // 在头节点前新建哑节点
    ListNode* cur=dummy;
    while (cur->next!=nullptr && cur->next->next!=nullptr)
    {
        if (cur->next->val==cur->next->next->val)
        {
            int tmp=cur->next->val;
            while (cur->next && cur->next->val==tmp)
                cur->next=cur->next->next; // 1个不留
        }
        else
        {
            cur=cur->next;
        }
    }
    return dummy->next;
}