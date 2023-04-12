#include <cstdlib>
#include <cassert>
#include "ListNode.h"
using namespace std;

ListNode::~ListNode()
{
	while(this->next)
	{
		ListNode *tmp = this->next; //暂存第二个节点的地址
		this ->next = this->next->next; //修改连接，指向第三个节点地址
		tmp->next = NULL; //被删节点的next赋空值
		delete tmp; //第二个节点是被删节点
	}
}

ListNode::ListNode(int arr[])
{
    int len=sizeof(arr)/sizeof(arr[0]);
    if (len==0) // ?
	this->val = arr[0];
    // this->next =nullptr;
	ListNode *cur = this;
	for(int i = 1; i<len; i++) //遍历n-1次
	{
		cur->next = new ListNode(arr[i]);
		cur = cur->next;//指向下一个节点
	}
}

void ListNode::print()
{
    if (!this) 
        cout<<"Null";
	ListNode *cur = this;
	while(cur)
	{
		cout<<cur->val;
		if(cur->next)
			cout<<"->";
		cur = cur->next; // 指向下一个节点
	}
}