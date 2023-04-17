// 合并两个升序列表-递归  l-21
/*输入：l1 = [1,2,4], l2 = [1,3,4]
  输出：[1,1,2,3,4,4]
*/
struct ListNode 
{
    int val;
    ListNode *next;
};

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