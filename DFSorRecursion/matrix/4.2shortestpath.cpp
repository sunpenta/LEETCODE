// 迷宫最短路径-dfs
// 有障碍；方向：下，右；输出：位置[i,j]
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>shortestPath(vector<vector<int>>& grid);

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 1},
        {0, 1, 0},
        {0, 0, 0}}; // input
    vector<vector<int>> ans = shortestPath(grid); // output: {(0,0),(1,0),(2,0),(2,1),(2,2)}
    for (auto loc : ans)
    {
        cout << "(" << loc[0] << "," << loc[1] << ")" << endl;
    }
    system("pause");
}
bool dfs(vector<vector<int>>&ans,vector<vector<int>>& grid, int row,int col)
{
    int m=grid.size(), n=grid[0].size();
    if (row>=m || col>=n || grid[row][col]==1) return false;
    if (row==m-1 && col==n-1)
    {
        ans.push_back({m-1,n-1});
        return true;
    }
    ans.push_back({row,col});
    if (dfs(ans,grid,row+1,col) || dfs(ans,grid,row,col+1))
     return true;

    ans.pop_back();
    return false;
}

vector<vector<int>>shortestPath(vector<vector<int>>& grid)
{
    vector<vector<int>>ans;
    dfs(ans,grid,0,0);
    return ans;
}