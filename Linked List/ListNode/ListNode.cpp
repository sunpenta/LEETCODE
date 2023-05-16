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

ListNode::ListNode(vector<int>& nums)
{
    int n=nums.size();
    this->val=nums[0]; 
    ListNode* cur=this;
    for (int i=1; i<n; i++) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    cur->next=nullptr;
}
/*
ListNode::~ListNode() // 析构
{
	while(this->next)
	{
		ListNode *tmp = this->next; // 暂存第二个节点的地址
		this ->next = this->next->next; // 修改连接，指向第三个节点地址
		tmp->next = NULL; // 被删节点的next赋空值
		delete tmp; // 第二个节点是被删节点
	}
}*/

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



