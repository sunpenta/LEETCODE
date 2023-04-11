#include <bits/stdc++.h>
using namespace std;
string solve(int n, size_t k);

int main()
{
    /*
    int t, n, k;
    cin>>t;
    while (t--) // t组
    {
        cin>>n>>k;
    }*/
    int n=64; size_t  k=73709551616;
    cout<<solve(n,k)<<endl;
}

string solve(int n, size_t  k) // 第n个字符串的第K个颜色
{
    vector<string> dp(n);
    dp[0]="r"; dp[1]="br";
    for (int i=2; i<n; i++)
    {
        size_t len=dp[i-1].size();
        string reversed=dp[i-1].substr(len/2)+dp[i-1].substr(0,len/2);
        dp[i]=reversed+dp[i-1];
    }
    return dp[n-1][k]=='r'?"red":"blue";
}
