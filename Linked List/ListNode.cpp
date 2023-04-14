#include <iostream>
#include "ListNode.h"
using namespace std;

ListNode* creatList(int arr[], int n)
{
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i=1; i<n; i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

void ListNode::print()
{
	ListNode *cur = this;
	while(cur)
	{
		cout<<cur->val<<" ";
		cur = cur->next; // 指向下一个节点
	}
	cout<<endl;
}