//两两交换链表中的节点 - 递归  l-24
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
    // 终止条件：链表中没有节点，或链表中只有一个节点
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* newHead = head->next; // 新链表的头节点变成原链表的第二个节点
    head->next = swapPairs(newHead->next); // 其它节点两两交换
    newHead->next = head; // 新链表的第二个节点变成原链表的头节点
    return newHead; // 返回交换后新链表的头节点
}
   