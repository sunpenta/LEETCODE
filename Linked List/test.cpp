#include "ListNode.h"
// ListNode* vectorToListNode(const vector<int>& nums);
int main()
{
    vector<int> nums={1,2,3};
    ListNode node;
    ListNode* head=node.vectorToListNode(nums);
    head->print();
    return 0;
}