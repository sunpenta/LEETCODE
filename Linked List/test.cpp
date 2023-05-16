#include "ListNode.h"
int main()
{
    vector<int> nums={1,2,3};
    ListNode* head=ListNode::vectorToListNode(nums);
    head->print();
    return 0;
}