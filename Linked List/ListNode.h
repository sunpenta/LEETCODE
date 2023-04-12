#ifndef LISTNODE_H
#define LISTNODE_H
#include <cstdlib>
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    // 输入输出
	ListNode(int arr[], int n);
	~ListNode();
	void printList();
};
#endif