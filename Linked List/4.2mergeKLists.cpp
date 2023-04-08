// 合并k个升序链表-优先队列  l-23
// 0 <= k <= 10^4
#include <bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    if (lists.size()==0) return nullptr;
    //从小到大排序（优先队列默认从大到小排序）
    struct cmp 
    {   // bool operator< :运算符重载
        bool operator() (const ListNode* a,const ListNode* b)//必须用const
        { 
            return a->val > b->val; //小的优先级高
        }
    };
    // 依次为：存储元素类型，承载数据结构堆底层容器，优先级
    priority_queue <ListNode*,vector<ListNode*>,cmp> q; 
    for (auto list: lists) //把每一个链表的头结点插入优先队列，队列自动排序
    {
        if (list!=nullptr) //判空
            q.push(list);
    }

    ListNode dummy(-1); // 新建一个值为-1的哑节点
    ListNode* p=&dummy; // 指向哑节点的指针p
    while (!q.empty())
    {
        ListNode* top=q.top(); // 优先队列的头节点
        q.pop();

        p->next=top; 
        while (top!=nullptr)
        {
            q.push(top->next); //?
        }
        p=p->next; 
    }
    return dummy.next; // 哑节点的下一个节点的地址
}