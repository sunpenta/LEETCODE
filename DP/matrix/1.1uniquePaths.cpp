// 不同路径（无障碍)-dp  l-62
// ->int; dfs TLE; 方向:向下, 或向右
#include <bits/stdc++.h>
using namespace std;
int uniquePaths(int m,int n);

int main()
{
    int m=4, n=5; // 输入：矩阵m * n
    cout<<uniquePaths(m,n)<<endl; // 输出
    system("pause");
}
// 状态转移方程:dp[i][j]=dp[i-1][j]+dp[i][j-1]; 
int uniquePaths(int m,int n)
{
    vector<vector<int>>dp(m,vector<int>(n)); // dp[i][j]:从[0,0]到[i][j]的方案数
    // 边界
    for (int i=0;i<m;i++) dp[i][0]=1;      
    for (int i=0;i<n;i++) dp[0][i]=1;        
    
    for (int i=1;i<m;i++)
    {
        for (int j=1;j<n;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}