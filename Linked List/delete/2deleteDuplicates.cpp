// 删除链表重复元素 l-83
// 保留1个重复元素；长度[0, 300], 链表按升序排列, Node.val∈[-100,100] 
#include "ListNode.h"
using namespace std;
ListNode* deleteDuplicates(ListNode* head);

int main()
{
    vector<int> nums={1,1,2,3,3};
    ListNode* head=ListNode::vectorToListNode(nums);
    ListNode* res=deleteDuplicates(head);
    res->print(); // output: 1 2 3
    return 0;
}

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* dummy=new ListNode(101,head); // 在头节点前新建哑节点，值在[-100,100]之外
    ListNode* cur=dummy;
    while (cur && cur->next)
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
    return dummy->next;
}