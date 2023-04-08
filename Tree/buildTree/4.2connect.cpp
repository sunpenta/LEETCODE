// 填充指向同层右节点的next指针(普通二叉树)-bfs  l-117
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
};

/* 输入:root={1,2,3,4,5,null,7}            //      1->nullptr
   输出:     {1,#,2,3,#,4,5,7,#}*/         //    2 -> 3->nullptr
Node* connect(Node* root)                 //  4 -> 5 ->  7->nullptr
{
    if (!root) return nullptr;
    queue<Node*>q;
    q.emplace(root);
    while (!q.empty())
    {
        int levelSize=q.size();
        Node* cur;
        for (int i=0;i<levelSize;i++) // 同一层节点
        {
            cur=q.front();
            q.pop();
            cur->next=q.front();
            if (cur->left) q.emplace(cur->left);
            if (cur->right) q.emplace(cur->right);
        }
        cur->next=nullptr;   // 一定加指向空指针
    }
    return root;
}