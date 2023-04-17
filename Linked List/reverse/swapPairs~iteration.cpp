// 两两交换链表中的节点 - 迭代  l-24
#include <iostream>
#include "C:\Users\Auly\Desktop\LEETCODE\leetcode\Linked List\ListNode.cpp"
using namespace std;
ListNode* swapPairs(ListNode* head);

int main()
{
    int arr[]={2,1,4,3}; // input
    int n=sizeof(arr)/sizeof(arr[0]);
    ListNode head(arr, n); 
    ListNode* res=swapPairs(&head); // output: 1 2 3 4
    res->print();
}

ListNode* swapPairs(ListNode* head) 
{

    ListNode* dummy = new ListNode(0,head); // 在头节点之前,新建一个值为0的哑节点
    ListNode* temp = dummy; // 将dummy赋给temp
        
    //终止条件：temp后只有一个节点
    while (temp->next != nullptr && temp->next->next != nullptr) 
    {
        ListNode* node1 = temp->next;
        ListNode* node2 = temp->next->next; //node1和node2是temp后两两相邻的节点
           
        //交换前:temp->node1->node2->?
        temp->next = node2; //temp->node2->?
        node1->next = node2->next; //node1->?
        node2->next = node1; //node2->node1->?
        temp = node1; //交换后：temp->node2->node1->? ;下一次循环交换后面两个节点
    }
    return dummy->next; //返回新链表
}