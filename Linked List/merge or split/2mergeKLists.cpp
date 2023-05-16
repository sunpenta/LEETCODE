// 合并k个升序链表 - 优先队列  l-23
// 0 <= k <= 10^4
#include <vector>
#include <queue>
#include "ListNode.h"
using namespace std;
ListNode* mergeKLists(vector<ListNode*>& lists);

int main()
{
    vector<vector<int>> nums={{1,2,4}, {2,3,5}, {0,1,3}};
    int n=lists_v.size();
    vector<ListNode*> lists(n);
    for (int i=0; i<n; ++i)
    {
        lists[i]=ListNode::vectorToListNode(nums[i]);
    }
    ListNode* res=mergeKLists(lists);
    res->print(); // output: 0 1 1 2 2 3 3 4 5
    return 0;
}

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    if (lists.size()==0) return nullptr;
    // 从小到大排序（优先队列默认从大到小排序）
    struct cmp 
    {
        bool operator() (const ListNode* a,const ListNode* b) // 必须用const
        { 
            return a->val > b->val; // ?
        }
    };
    // 依次为：存储元素类型, 承载数据结构堆底层容器, 优先级
    priority_queue <ListNode*, vector<ListNode*>, cmp> pq; 
    for (auto& list: lists) // 把每一个链表的头结点插入优先队列，队列自动排序
    {
        if (list) // 判空
            pq.push(list);
    }

    ListNode dummy(-1);
    ListNode* p = &dummy;
    while (!pq.empty())
    {
        ListNode* tmp=pq.top(); // 优先队列的头节点
        pq.pop();

        p->next=tmp; 
        if (tmp->next)
        {
            pq.push(tmp->next);
        }
        p=p->next; 
    }
    return dummy.next;
}