// 交错字符串-动态规划+滚动数组  l-94
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
// dp[i]只和dp[i-1]有关
bool isInterleave(string s1,string s2,string s3)
{
    int m=s1.length(), n=s2.length(), t=s3.length();
    if (m+n!=t) return false; // 长度不等
    vector<int>dp(n+1,false); // dp[i][j]:s1[0,i)和s2[0,j)交错组成?s3[i+j-1); 不要用bool
    dp[0]=true; // 
    for (int i=0;i<=m;i++)
    {
        for (int j=0;j<=n;j++)
        {
            int p=i+j-1; // s3[p]
            if (i>0 && s1[i-1]!=s3[p]) // 一定要用!=,例：s1="a",s2="",s3="c"
  /*或写成： if (i>0)
                dp[j]&=s1[i-1]==s3[p]; */
                dp[j]=false; 
            if (j>0 && s2[j-1]==s3[p])
                dp[j]|=dp[j-1];
        }
    }
    return dp[n];
}