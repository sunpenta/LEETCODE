// K个一组翻转链表(不修改节点内部的值,只能进行节点交换)  l-25
#include "ListNode.h"
ListNode* reverseKGroup(ListNode* head, int k);

int main()
{
    vector<int> nums={1,2,3,4,5}; 
    ListNode* head=ListNode::vectorToListNode(nums); int k=3; // input
    ListNode* res=reverseKGroup(head, k); // output: 3,2,1,4,5
    res->print();
}

// 翻转长度为k的子链表
ListNode* reverse(ListNode* head)
{
    ListNode* pre = nullptr, *cur=head;     
    while (cur)
    {
        ListNode* next = cur->next; // 暂存
        cur->next = pre;            // 翻转
        // update
        pre = cur;
        cur = next;
    }
    return pre;
}

// 每K组翻转一次链表，不足K组的子链表保持原状
ListNode* reverseKGroup(ListNode* head, int k)
{ 
    ListNode* dummy = new ListNode(0,head); // 在head节点前新建一个哑节点

    // 辅助指针
    ListNode* pre = dummy; // pre指向每次翻转链表的头节点的上一个节点
    ListNode* end = dummy; // pre指向每次翻转链表的尾节点

    //遍历链表；判断条件：链表不为空
    while (end->next != nullptr)
    {
        // end向右移动k个节点，且end不为空
        for (int i = 0; i < k && end != nullptr; i++)
            end = end->next;
        // 如果end为空，则剩下子链表长度小于k
        if (end == nullptr) 
            break; 
        // 辅助指针
        ListNode *start = pre->next; // 当前翻转子链表的头节点
        ListNode *next = end->next;  // 下一次翻转子链表的头节点

        end->next = nullptr; // 翻转子链表的尾节点设为空，那么以start为头节点的子链表长度为k
        pre->next=reverse(start);  // pre -> 翻转子链表的头节点
        start->next = next; // 断链重连:子链的头节点成为尾节点，指向下一次翻转链表的头节点
  
        pre = start; // 调整辅助指针
        end = start;  
    }
    return dummy->next;
}