// 课程表II-BFS/kahn's  l-210
// 课程号：0-numCourses-1; prerequisites[i] = [ai, bi], bi->a1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);

int main()
{
    int numCourses=4; vector<vector<int>> prerequisites={{1,0},{2,0},{3,1},{3,2}}; // input
    vector<int> res=findOrder(numCourses,prerequisites);
    for (int i:res) cout<<i<<" "; // output:{0,1,2,3} 或 {0,2,1,3}
    system("pause");
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    // bulit graph
    vector<vector<int>> graph(numCourses); vector<int> indeg(numCourses);
    for (auto edge:prerequisites)
    {
        graph[edge[1]].emplace_back(edge[0]);
        ++indeg[edge[0]];
    }

    queue<int> q; // <index:indeg[index]==0>
    for (int i=0; i<numCourses; i++)
        if (indeg[i]==0) q.push(i);
    
    vector<int> res;
    while (!q.empty())
    {
        int node=q.front();
        q.pop();
        res.emplace_back(node);
        for (int neigbor:graph[node])
        {
            --indeg[neigbor];
            if (indeg[neigbor]==0)
                q.push(neigbor);
        }
    }
    return res.size()==numCourses?res:vector<int>{};
}