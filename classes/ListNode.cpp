#include "ListNode.h"

using std::cout;
using std::endl;
void ListNode::print()
{
	ListNode* cur = this;
	while(cur && cur->next)
	{
		std::cout<<cur->val<<"->";
		cur = cur->next;
	}
    if (cur)
        cout<<cur->val<<endl;
    else
        cout<<"Empty LinkedList"<<endl;
}
ListNode* ListNode::vectorToListNode(vector<int>& nums)
{
    ListNode* dummy=new ListNode(0);
    ListNode* p=dummy;    
    for (int num:nums) 
    {
        p->next = new ListNode(num);
        p = p->next;
    }
    p->next=nullptr;
    p=dummy->next;
    delete dummy;
    return p;
}