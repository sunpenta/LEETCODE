// 删除链表倒数第N个节点  l-19
#include "ListNode.h"
#include <iostream>
ListNode* removeNthFromEnd(ListNode* head,int n);
void foo() {
    std::cout << "Entering foo()" << std::endl;

    // do some stuff
    int arr[4]={2,1,4,3}; 
    ListNode head(arr, 4); int n=2;
    ListNode* res=removeNthFromEnd(&head,n);
    res->print(); // output: 2 1 3

    std::cout << "Leaving foo()" << std::endl;
}
int main()
{
    std::cout << "Starting main()" << std::endl;

    foo();

    std::cout << "Exiting main()" << std::endl;

    return 0;
}

int getLength(ListNode* head)
{
    int length=0;
    while (head)
    {
        length++;
        head=head->next;
    }
    return length;
}

ListNode* removeNthFromEnd(ListNode* head,int n)
{
    ListNode* dummy=new ListNode(0,head); // 因为头节点可能被删除，在头节点之前，新建一个哑节点
    int length=getLength(head);
    ListNode* cur=dummy; // 最后的结果指向dummy，可以获取dummy的全部结果
    for (int i=0;i<length-n;i++) 
        cur=cur->next; // 指向倒数第n-1个节点
    cur->next=cur->next->next; // 跳过原链表中的倒数第n个节点
    ListNode* ans=dummy->next; 
    delete dummy;  // 删除哑节点
    return ans;
}