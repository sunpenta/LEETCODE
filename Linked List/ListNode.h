#ifndef LISTNODE_H
#define LISTNODE_H

#pragma once
using namespace std;
class ListNode
{
    public:
        int val;
        ListNode *next;
    
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
        ~ListNode() {}
        void print();
        friend ListNode* creatList(int arr[], int n); // 不可以用sizeof(arr)/sizeof(arr[0]), 数组作参数，是1个指针，sizeof(arr)=4
        
};

#endif