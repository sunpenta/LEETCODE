// 使字符串成为palindrome的最小步骤 - dp  l-1312
// 每一步，可在字符串的任一位置插入任一字母; length⋿[1,500]
#include <iostream>
#include <vector>
using namespace std;
int minInsertions(string s);

int main()
{
    string s="abca"; // input
    cout<<minInsertions(s)<<endl; // output:1 "abcba" "acbca"
}

int minInsertions(string s)
{
    int n=s.length();
    vector<vector<int>> dp(n,vector<int>(n)); // dp[i][j]: s[i,j]成为palindrome最短步骤
    for (int i=n-2; i>=0; --i) // [i,j]
    {
        for (int j=i+1; j<n; ++j)
        {
            if (s[i]==s[j])
                dp[i][j]=dp[i+1][j-1];
            else
                dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
        }
    }
    return dp[0][n-1];
}