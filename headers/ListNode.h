#ifndef LISTNODE_H
#define LISTNODE_H

#pragma once
#include <iostream>
#include <vector>
using std::vector;

class ListNode{
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *p) : val(x), next(p) {} 
    ~ListNode() {}

    void print();      
    static ListNode* vectorToListNode(vector<int>& nums); // 用friend出错
    // ListNode* head=ListNode::vectorToListNode(nums);
};
#endif
