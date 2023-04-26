// 分割回文串 - dp+dp  l-132  -dfs/string/5
// s.length⋿[1,2000]; 最少分割次数
#include <iostream>
#include <vector>
using namespace std;
int minCut(string s);

int main()
{
    string s="cbccccbc"; // input
    cout<<minCut(s)<<endl; // output:0
    return 0;
}

int minCut(string s)
{
    int n=s.length();
    vector<vector<int>> dp(n,vector<int>(n,true)); // dp[i][j]:s[i,j]是回文串
    for (int i=n-1; i>=0; i--)
    {
        for (int j=i+1; j<n; j++)
        {
            dp[i][j]=(s[i]==s[j]) && dp[i+1][j-1];
        }
    }

    vector<int> f(n,INT_MAX); // f[i]:s[0,i]的分割方案数
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