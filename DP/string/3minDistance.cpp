// 编辑距离-动态规划+分类  l-72
// 0 <= word1.length, word2.length <= 500
#include <bits/stdc++.h>
using namespace std;
int minDistance(string word1, string word2);

int main()
{
    string word1 = "horse"; string word2 = "ros"; // 输入
    cout<<minDistance(word1,word2)<<endl; // 输出
    system("pause");
}

// 从word1变成word2的最少操作
int minDistance(string word1, string word2)
{
    int m=word1.length(); int n=word2.length();
    // 特殊情况：其中1个字符串为空
    if (m*n==0) return m+n;
    vector<vector<int>>dp(m+1,vector<int>(n+1)); // dp[i][j]:word1的前i(不包含i)和word2的前j字符串的编辑距离
    // 边界
    for (int i=0;i<m+1;i++) // 第1列
        dp[i][0]=i;
    for (int i=0;i<n+1;i++) // 第1行
        dp[0][i]=i;
    for (int i=1;i<m+1;i++)
    {
        for (int j=1;j<n+1;j++)
        {
            dp[i][j]=min(min(dp[i-1][j]+1, dp[i][j-1]+1),dp[i-1][j-1]+int(word1[i-1]!=word2[j-1]));
/*相当于：   if (word1[i-1]==word2[j-1])
                dp[i][j]=min(min(dp[i-1][j]+1, dp[i][j-1]+1),dp[i-1][j-1]);
            else
                dp[i][j]=1+min(min(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1]);*/
        }
    }
    return dp[m][n];
}