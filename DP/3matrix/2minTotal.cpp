// 三角形的最小路径和-dp  l-120  -dfs
#include <bits/stdc++.h>
using namespace std;
int minTotal(vector<vector<int>>&triangle);

int main()
{
    vector<vector<int>>triangle={
        {1},
        {3,4},
        {6,5,7}
    }; // 输入
    cout<<minTotal(triangle)<<endl; // 输出:9 1+3+5=9
    system("pause");
}

int minTotal(vector<vector<int>>&triangle)
{
    int n=triangle.size();
    vector<vector<int>> dp;
    for (int i=0;i<n;i++) // 初始化
        dp.emplace_back(vector<int>(i+1)); 
    // 边界
    dp[0][0]=triangle[0][0];
    for (int i=1;i<n;i++)
    {
        dp[i][0]=dp[i-1][0]+triangle[i][0]; // 左边界
        dp[i][i]=dp[i-1][i-1]+triangle[i][i]; // 右边界
    }

    for (int i=1;i<n;i++)
    {
        for (int j=1;j<i;j++) // col [1,i-1]
        {
            dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
        }
    }
    return *min_element(dp[n-1].begin(),dp[n-1].end());
}