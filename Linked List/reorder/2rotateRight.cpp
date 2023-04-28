// 旋转链表-链表节点右移  l-61
#include "C:\Users\Auly\Desktop\LEETCODE\leetcode\Linked List\ListNode.cpp"
using namespace std;
ListNode* rotateRight(ListNode* head, int k);

int main()
{
    int arr[]={1,2,3,4,5}; 
    int n=sizeof(arr)/sizeof(arr[0]);
    ListNode head(arr, n); int k=2; // input
    ListNode* res=rotateRight(&head, k); // output: 4,5,1,2,3
    res->print();
}

ListNode* rotateRight(ListNode* head, int k) 
{
    // 特殊情况：k为0，或链表为空，或链表只有一个节点
    if (!k || !head || head->next==nullptr)
        return head;
   
    int n=1; //链表长度
    ListNode* tail=head;//尾节点
    while(tail->next!=nullptr)
    {
        tail=tail->next;
        n++;
    }
 
    k%=n;
    if (k==0) return head; // k是链表长度的整数倍
    
    tail->next=head; //链表头尾相连
    ListNode* p=head; 
    for (int i=0;i<n-k-1;i++) // 找到链表的第n-k个（倒数第k+1）节点
        p=p->next;   

    head=p->next;  //重置链表头尾
    p->next=nullptr;

    return head;
}