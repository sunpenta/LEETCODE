// 合并两个升序列表-递归  l-21
#include "C:\Users\Auly\Desktop\LEETCODE\leetcode\Linked List\ListNode.cpp"
using namespace std;
ListNode* mergeTwoLists(ListNode* l1,ListNode* l2);

int main()
{
    int arr1[]={1,2,4}, arr2[]={1,3,4}; 
    int n1=sizeof(arr1)/sizeof(arr1[0]), n2=sizeof(arr2)/sizeof(arr2[0]);
    ListNode l1(arr1, n1); ListNode l2(arr2,n2);
    ListNode* res=mergeTwoLists(&l1,&l2);
    res->print(); // output: 1,1,2,3,4,4
}

ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
{
    if (l1==nullptr) // 其中1个是空链表
        return l2; 
    else if (l2==nullptr) 
        return l1;
    else if (l1->val < l2->val)
    {
        l1->next=mergeTwoLists(l1->next,l2);
        return l1;
    }
    else
    {
        l2->next=mergeTwoLists(l1,l2->next);
        return l2;
    }
}