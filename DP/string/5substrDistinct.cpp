// 不同的子序列-动态规划  l-115  -slideWindow/2.1
#include <bits/stdc++.h>
using namespace std;
int substrDistinct(string s,string t);

int main()
{
    string s="babgbag", t="bag"; // 输入
    cout<<substrDistinct(s,t)<<endl; // 输出:5
    system("pause");
}

int substrDistinct(string s,string t)
{
    int m=s.length(), n=t.length();
    vector<vector<int>>dp(m+1,vector<int>(n+1)); // dp[i][j]:s[0,i)包含t[0,j)的方案数
    // 边界
    for (int i=0;i<=m;i++)
        dp[i][0]=1;   // 任意字符串都包含空字符串
    for (int i=1;i<=m;i++)
    {
        for (int j=0;j<=n;j++)
        {
            if (s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j]; // 状态转移方程
            else
                dp[i][j]=dp[i-1][j];
        }
    }
}