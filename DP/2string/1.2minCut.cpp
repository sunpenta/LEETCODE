// 最少分割次数-dp+dp  l-132  -parlindrome
// 每个substring都是回文串; s.length∈[1,2000]
#include <bits/stdc++.h>
using namespace std;
int minCut(string s);

int main()
{
    string s="cbccccbc"; // 输入
    cout<<minCut(s)<<endl; // 输出:1
    system("pause");
}

int minCut(string s)
{
    int n=s.length();
    vector<vector<int>>dp(n,vector<int>(n,true)); // dp[i][j]:s[i,j]is parlindrome
    for (int i=n-1;i>=0;i--)
    {
        for (int j=i+1;j<n;j++)
        {
            dp[i][j]=(s[i]==s[j]) && dp[i+1][j-1];
        }
    }

    vector<int>f(n,INT_MAX); // f[i]:s[0,i]的最小分割次数
    for (int i=0;i<n;i++)
    {
        if (dp[0][i]) 
            f[i]=0;
        else
        {
            for (int j=0;j<i;j++)
            {
                if (dp[j+1][i])
                    f[i]=min(f[i],f[i-1]+1);
            }
        }    
    }
    return f[n-1];
}