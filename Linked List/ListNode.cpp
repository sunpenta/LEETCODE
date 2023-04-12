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

ListNode::ListNode(int arr[],int n)
{
	this->val = arr[0];this->next =nullptr;
	ListNode *current = this;
	for(int i = 1;i<n;i++) //遍历n-1次
	{
		current->next = new ListNode(arr[i]);
		current = current->next;//指向下一个节点
	}
}

void ListNode::printList()
{
	ListNode *current = this;
	while(current)
	{
		printf("%d",current->val);
		if(current->next!=NULL)
			printf("->");
		current = current->next; // 指向下一个节点
	}
}