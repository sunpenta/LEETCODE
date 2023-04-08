// 被包围区域数-dfs l-1254
// 0:land, 1:water; 0的上下左右被1包围
#include <bits/stdc++.h>
using namespace std;
int closedIslands(vector<vector<int>>& grid);

int main()
{
    vector<vector<int>> grid = {
        { 1, 1, 1, 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 0, 1, 1, 0 },
        { 1, 0, 1, 0, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 0, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 0 }
    }; // input
    cout<<closedIslands(grid)<<endl; // output:2
    system("pause");
}
// mark not closed
void dfs(vector<vector<int>> &grid, int i, int j)
{
    int m = grid.size(), n = grid[0].size();
    if (i<0 || i>=m || j<0 || j>=n || grid[i][j]!=0)
        return;
    grid[i][j]=1;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    for (int k=0;k<4;k++)
    {
        int nx=i+dx[k], ny=j+dy[k];
        dfs(grid,nx,ny);
    }
}
int closedIslands(vector<vector<int>> &grid)
{
    int m=grid.size(), n=grid[0].size();
    // board cell
    for (int i=0;i<m;i++) 
    {
        dfs(grid,i,0);
        dfs(grid,i,n-1);
    }
    for (int i=0;i<n;i++)
    {
        dfs(grid,0,i);
        dfs(grid,m-1,i);
    }
    int number=0;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (grid[i][j]==0)
            {
                dfs(grid,i,j);
                number++;
            }
        }
    }
    return number;
}
