#include <iostream>
#include "ListNode.h"
using namespace std;

ListNode::ListNode(int arr[], int n)
{
    this->val=arr[0]; 
    ListNode* cur=this;
    for (int i=1; i<n; i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    cur->next=nullptr;
}

void ListNode::print()
{
	ListNode* cur = this;
	while(cur)
	{
		cout<<cur->val<<" ";
		cur = cur->next; // 指向下一个节点
	}
	cout<<endl;
}



