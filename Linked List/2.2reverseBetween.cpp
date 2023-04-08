// 反转链表  l-92
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/* 输入：head = [1,2,3,4,5], left = 2, right = 4
   输出：       [1,4,3,2,5]*/
// 1. 一次遍历-头插法
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