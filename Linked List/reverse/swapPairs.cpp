//两两交换链表中的节点 - 原地  l-24
/* 输入：head = [1,2,3,4]
   输出：       [2,1,4,3] */
#include <list>
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1.递归法
ListNode* swapPairs(ListNode* head) 
{
    //终止条件：链表中没有节点，或链表中只有一个节点
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* newHead = head->next; // 新链表的头节点变成原链表的第二个节点
    head->next = swapPairs(newHead->next); //其它节点两两交换
    newHead->next = head; //新链表的第二个节点变成原链表的头节点
    return newHead; //返回交换后新链表的头节点
}

// 2.迭代法
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