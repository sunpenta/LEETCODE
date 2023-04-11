// 交错字符串-动态规划  l-94
// s3是否由s1和s2交错组成; 0 <= s1.length, s2.length <= 100; 0 <= s3.length <= 200
#include <bits/stdc++.h>
using namespace std;
bool isInterleave(string s1,string s2,string s3);

int main()
{
    // string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"; // true
    string s1="aabcc", s2 = "dbbca", s3 = "aadbbbaccc"; // 输入
    cout<<boolalpha<<isInterleave(s1,s2,s3)<<endl; // 输出:false
    system("pause");
}

bool isInterleave(string s1,string s2,string s3)
{
    int m=s1.length(), n=s2.length(), t=s3.length();
    if (m+n!=t) return false; // 长度不等
    vector<vector<int>>dp(m+1,vector<int>(n+1)); // dp[i][j]:s1[0,i)和s2[0,j)->s3[0,i+j-1); bool不能|=
    dp[0][0]=1; // edge
    for (int i=0;i<=m;i++) // ==m
    {
        for (int j=0;j<=n;j++) 
        {
            int p=i+j-1; // s3[p]
            if (i>0 && s1[i-1]==s3[p])
                dp[i][j]|=dp[i-1][j]; // |=: 若s1是ture,s2判断是false,则影响后面运算
/*或写成：   if (i>0)
                dp[i][j]=dp[i-1][j] && s1[i-1]==s3[p]; */ 
            if (j>0 && s2[j-1]==s3[p])
                dp[i][j]|=dp[i][j-1];
        }
    }
    return dp[m][n];
}