#include <bits/stdc++.h>
using namespace std;
string solve(int n, int k);

int main()
{
    int t, n, k;
    cin>>t;
    while (t--) // t组
    {
        cin>>n>>k;
    }
    cout<<solve(n,k)<<endl;
}

string solve(int n, int k) // 第n个字符串的第K个颜色
{
    vector<string> dp(n);
    dp[0]="r"; dp[1]="br";
    for (int i=2; i<n; i++)
    {
        string reversed(dp[i-1].rbegin(),dp[i-1].rend());
        dp[i]=reversed+dp[i-1];
    }
    return dp[n-1][k]=='r'?"red":"blue";
}
