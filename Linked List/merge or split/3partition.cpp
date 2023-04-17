// 分隔链表  l-86
// -100 <= Node.val <= 100; -200 <= x <= 200
#include "C:\Users\Auly\Desktop\LEETCODE\leetcode\Linked List\ListNode.cpp"
using namespace std;
ListNode* partition(ListNode*head, int x);

int main()
{
    int arr[]={1,2,3,4}; 
    int n=sizeof(arr)/sizeof(arr[0]);
    ListNode l(arr, n); int x=2;
    ListNode* res=partition(&l, x);
    res->print(); // output: 1 2 3
}

ListNode* partition(ListNode*head, int x)
{
    // 特殊情况：空链表，或链表只有1个元素
    if (!head || !head->next) return head;

    ListNode* tail=head; // 尾节点
    int len=1; // 链表长度
    while (tail->next)  // 相当于tail->next!=nullptr，注意无 !
    {
        tail=tail->next;
        len++;
    }

    ListNode* dummy=new ListNode(201,head); // 在head前新建哑节点
    ListNode* cur=dummy;
    for (int i=0;i<len;i++)
    {
        if (cur->next->val>=x && !cur->next->next) // 如果只剩1个节点，则无需挪动
        {
            ListNode* tmp=cur->next; // 暂存
            cur->next=cur->next->next; // 移除
            tail->next=tmp; // 加在尾节点后
            tail=tail->next; // 更新尾节点
        }
        else
        {
            cur=cur->next;
        }
    }
    tail->next=nullptr;
    ListNode* ans=dummy->next;
    delete dummy;
    return ans;
}