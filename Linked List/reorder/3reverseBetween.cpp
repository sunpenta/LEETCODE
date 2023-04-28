// 反转链表- 一次遍历-头插法  l-92
#include "C:\Users\Auly\Desktop\LEETCODE\leetcode\Linked List\ListNode.cpp"
ListNode* reverseBetween(ListNode*head,int left,int right);

int main()
{
    int arr[]={1,2,3,4,5}; 
    int n=sizeof(arr)/sizeof(arr[0]);
    ListNode head(arr, n); int left = 2, right = 4; // input
    ListNode* res=reverseBetween(&head, left, right); // output: 1,4,3,2,5
    res->print();
}

ListNode* reverseBetween(ListNode*head,int left,int right)
{
    ListNode* dummy=new ListNode(0,head); // 在头节点前，新建哑节点
    ListNode* pre=dummy; // left前的节点，不动
    for (int i=0;i<left-1;i++)
        pre=pre->next;
    ListNode* cur=pre->next; // 反转的第1个节点（left节点），不动
    ListNode* next; // 反转的第2个节点
    for (int i=left;i<right;i++)
    {
        next=cur->next; 
        cur->next=next->next; // 第1个节点与后面相连
        next->next=pre->next; // 头插：第2个节点插在pre后面(即left位置)
        pre->next=next; // 第2个节点与前面相连
    }
    ListNode* ans=dummy->next;
    delete dummy;
    return ans;
}