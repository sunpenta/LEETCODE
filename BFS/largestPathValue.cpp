// 有向图的最多颜色 - bfs/拓扑排序  l-1857
// 时间复杂度:O(n), 空间复杂度:O(n); 若有向图有环,返回-1；否则，返回所有路径最大颜色值
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int largestPathValue(string colors, vector<vector<int>>& edges);

int main()
{
    string colors="abaca"; vector<vector<int>>edges = {{0,1},{0,2},{2,3},{3,4}}; // input
    cout<<largestPathValue(colors,edges)<<endl; // ouput:3
    return 0;
}

int largestPathValue(string colors, vector<vector<int>>& edges)
{
    int n=colors.length();
    vector<vector<int>> graph(n); vector<int> indeg(n); // 初始化size
    for (auto edge:edges)
    {
        if (edge[0]==edge[1]) // self cycle
            return -1;
        graph[edge[0]].emplace_back(edge[1]);
        ++indeg[edge[1]];
    }
    
    queue<int> q; // indeg[]=0
    for (int i=0; i<n; ++i)
    {
        if (indeg[i]==0)
        {
            q.push(i);
        }
    }
    vector<vector<int>> colored(n,vector<int>(26)); // colored[i][j]:path end with node i最多有?j+'a'颜色
    int visit=0, res=0; // nodes number visited
    while (!q.empty())
    {
        int node=q.front();
        q.pop();
        ++visit;
        ++colored[node][colors[node]-'a'];
        res=max(res,colored[node][colors[node]-'a']);
        for (int neighbor:graph[node])
        {
            for (int i=0; i<26; ++i)
            {
                colored[neighbor][i]=max(colored[node][i],colored[neighbor][i]);
            }
            --indeg[neighbor];
            if (indeg[neighbor]==0)
                q.push(neighbor);
        }
    }
    return visit==n?res:-1;
}
