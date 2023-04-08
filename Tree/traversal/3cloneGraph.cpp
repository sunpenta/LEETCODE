// 克隆图-hash+dfs  l-133  -List/5
// Definition for a Node.
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

unordered_map<Node*,Node*>visit; // 记录已访问的节点，避免死循环
Node* cloneGraph(Node* node)
{
    if (!node) return nullptr;
    if (visit.count(node)) // 已访问过，结束遍历
        return visit[node];
    Node* copy=new Node(node->val);
    visit[node]=copy;
    for (auto neighbor:node->neighbors) // 遍历邻居节点
    {
        copy->neighbors.emplace_back(cloneGraph(neighbor));
    }
    return copy;
}