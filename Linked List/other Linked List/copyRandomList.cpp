// 深拷贝带随机指针的链表-hash  l-138  -Tress/traversal/3
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

unordered_map<Node*,Node*>visit;
Node* copyRandomList(Node* head)
{
    if (!head) return nullptr;
    if (!visit.count(head))
    {
        Node* copy=new Node(head->val);
        visit[head]=copy; // 标记已遍历
        copy->next=copyRandomList(head->next);
        copy->random=copyRandomList(head->random);
    }
    return visit[head]; // *注意返回值*
}