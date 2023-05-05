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
    vector<vector<int>> colored(n,vector<int>(26)); // colored[i][j]:path end with node i have color j+'a'
    for (int i=0; i<n; ++i)
    {
        if (indeg[i]==0)
        {
            q.push(i);
            colored[i][color[i]-'a']=1;
        }
    }

    int visit=0; // nodes number visited
    while (!q.empty())
    {
        int node=q.front();
        q.pop();
        ++visit;

        for (neighbor:graph[node])
        {
            for (int i=0; i<26; ++i)
            {
                colored[node][i]=max(colored[node][i]+(colored[neighbor]==i+'a'),colored[neighbor][i]);
            }
            --indeg[neighbor];
            if (indeg[neighbor]==0)
                q.push(neighbor);
        }
    }
    int res=0;
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<26; ++j)
            res=max(res,colored[i][j]);
    }
    return res;
}
