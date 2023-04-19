// 被包围区域-dfs l-130  -l-1020
// 'O' is closed by 'X'; 把被包围区域的'O'变成'X'
#include <bits/stdc++.h>
using namespace std;
void slove(vector<vector<char>> &grid);

int main()
{
    vector<vector<char>> grid={
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    }; // input
    slove(grid); 
    for (auto row : grid)
    {
        cout<<"{";
        for (char col:row)
            cout<<"\""<<col<<"\","; // '在终端显示太ugly
        cout<<"}\n";
    } // output:2
    system("pause");
}
// 
void dfs(vector<vector<char>> &grid, int i, int j)
{
    int m = grid.size(), n = grid[0].size();
    if (i<0 || i>=m || j<0 || j>=n || grid[i][j]!='O')
        return;
    grid[i][j]='#';
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    for (int k=0;k<4;k++)
    {
        int nx=i+dx[k], ny=j+dy[k];
        dfs(grid,nx,ny);
    }
}

void slove(vector<vector<char>>& grid)
{
    int m=grid.size(), n=grid[0].size();
    // board cell
    for (int i=0; i<m; i++)
    {
        dfs(grid,i,0); // 左边
        dfs(grid,i,n-1); // 右边
    }
    for (int i=0; i<n; i++)
    {
        dfs(grid,0,i); // 上边
        dfs(grid,m-1,i); // 下边
    }

    for (int i=0; i<m; i++)
    {
        for (int j=0;j<n;j++)
        {
            if (grid[i][j]=='#')
                grid[i][j]='O';
            else
                grid[i][j]='X';
        }
    }
}