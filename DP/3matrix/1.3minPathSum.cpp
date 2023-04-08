// 最小路径和-动态规划  l-64
// 方向：只能向右或向下
#include <bits/stdc++.h>
using namespace std;
int minPathSum(vector<vector<int>>& grid);

int main()
{
    vector<vector<int>>grid={
        {1,2,3},
        {4,5,6},
        {1,2,3}}; // 输入
    cout<<minPathSum(grid)<<endl; // 输出:11 1->4->1->2->3 
    system("pause");
}
// 状态转移方程:dp[i][j]=min(min(dp[i-1][j],dp[i][j-1])+grid[i][j]
int minPathSum(vector<vector<int>>& grid)
{
    int m=grid.size(); int n=grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n)); // dp[i][j]:从[0,0]到[i][j]的最小路径和
    // 边界
    dp[0][0]=grid[0][0];
    for (int i=1;i<m;i++) // 第1列,从1开始
        dp[i][0]=dp[i-1][0]+grid[i][0];
    for (int i=1;i<n;i++) // 第1行，从1开始
        dp[0][i]=dp[0][i-1]+grid[0][i];

    for (int i=1;i<m;i++) // 行
    {
        for (int j=1;j<n;j++) // 列
        {
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j]; // 状态转移方程
        }
    }
    return dp[m-1][n-1];
}