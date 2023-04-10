// 不同路径（有障碍）-动态规划+分类 l-63  -DFSorRecursion/matrix/shortestPath
// ->int; 方向：向右或向下; '1'：障碍，'0'：空格
#include <bits/stdc++.h>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& grid);

int main()
{
    vector<vector<int>>grid={
        {0,0,1},
        {0,1,0},
        {0,0,0}
    }; // 输入
    cout<<uniquePathsWithObstacles(grid)<<endl; // 输出:1
    system("pause");
}

int uniquePathsWithObstacles(vector<vector<int>>& grid)
{
    int m=grid.size(), n=grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n)); // dp[i][j]:从[0][0]到[i][j]的方案数
    // 边界
    for (int i=0;i<m && grid[i][0]==0;i++) dp[i][0]=1; 
    for (int i=0;i<n && grid[0][i]==0;i++) dp[0][i]=1; 

    for (int i=1;i<m;i++) 
    {
        for (int j=1;j<n;j++)
        {
            if (grid[i][j]==0) // space
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            else // obstacle
                dp[i][j]=0; 
        }
    }
    return dp[m-1][n-1];
}