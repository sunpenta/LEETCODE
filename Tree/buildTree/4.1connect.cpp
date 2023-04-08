// 填充指向同层右节点的next指针(完美二叉树)-分类  l-116
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
};
/* 输入:{1,2,3,4,5,6,7}                  //        1->nullptr
   输出:{1,#,2,3,#,4,5,6,7,#}*/          //      2 -> 3->nullptr
Node* connect(Node* root)               //     4->5->6->7->nullptr
{
    if (!root) return nullptr;
    Node *leftmost=root;   // 一层最左节点
    while (leftmost->left)
    {
        Node* cur=leftmost; // 填充leftmost下一层的next
        while (cur)
        {
            cur->left->next=cur->right; // connect1:有相同的父节点cur
            if (cur->next)
            {
                cur->right->next=cur->next->left; // connect2:父节点相邻
            }
            cur=cur->next;
        }
        leftmost=leftmost->left; // 去下一层
    }
    return root;
}