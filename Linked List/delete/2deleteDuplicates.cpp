// 删除链表重复元素 l-83
// 长度[0, 300]; -100 <= Node.val <= 100 链表按升序排列
#include "C:\Users\Auly\Desktop\LEETCODE\leetcode\Linked List\ListNode.cpp"
using namespace std;
ListNode* deleteDuplicates(ListNode* head);

int main()
{
    int arr[]={1,1,2,3,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    ListNode head(arr, n);
    ListNode* res=deleteDuplicates(&head);
    res->print(); // output: 
}

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* dummy=new ListNode(INT_MAX,head); // 在头节点前新建哑节点，值在[-100,100]之外
    ListNode* cur=dummy;
    while (cur!=nullptr && cur->next!=nullptr)
    {
        if (cur->val==cur->next->val)
        {
            cur->next=cur->next->next; // 保留1个
        }
        else
        {
            cur=cur->next;
        }
    }
    ListNode* ans=dummy->next;
    delete dummy;
    return ans;
}