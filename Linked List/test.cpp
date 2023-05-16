#include "ListNode.h"
ListNode* vectorToListNode(const vector<int>& nums);
int main()
{
    vector<int> nums={1,2,3};
    ListNode* head=vectorToListNode(nums);
    head->print();
}