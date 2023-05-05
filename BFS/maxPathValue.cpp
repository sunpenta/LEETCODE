// 有向图的最多颜色值 - bfs  l-1857
// 时间复杂度: 空间复杂度:
#include <iostream>
#include <vector>
#include <queue>
using namespace;
int maxPathValue(string color, vector<vector<int>>& edges);

int main()
{

}

int maxPathValue(string color, vector<vector<int>>& edges)
{
    vector<vector<int>> graph; vector<int> indeg;
    for (auto edge:edges)
    {
        graph[edge[0]].emplace(edge[1]);
        ++indeg[edge[1]];
    }
    queue<int> q; // indeg[]=0
    int n=color.length();
    for (int i=0; i<n; ++i)
    {
        if (indeg[i]==0)
            q.push(i);
    }

    int visit=0; // nodes number visited
    while (!q.empty())
    {
        int node=q.front();
        q.pop();
        ++visit;
        
    }

}
