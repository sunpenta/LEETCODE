// ���ٷָ����-dp+dp  l-132  -dfs/string/5
// s.length��[1,2000]
#include <bits/stdc++.h>
using namespace std;
int minCut(string s);

int main()
{
    string s="cbccccbc"; // ����
    cout<<minCut(s)<<endl; // ���:1
    system("pause");
}

int minCut(string s)
{
    int n=s.length();
    vector<vector<int>>dp(n,vector<int>(n,true));
    for (int i=n-1;i>=0;i--)
    {
        for (int j=i+1;j<n;j++)
        {
            dp[i][j]=(s[i]==s[j]) && dp[i+1][j-1];
        }
    }

    vector<int>f(n,INT_MAX); // f[i]:s[0,i]����С�ָ����
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
        cout<<i<<" "<<f[i]<<endl;    
    }
    return f[n-1];
}