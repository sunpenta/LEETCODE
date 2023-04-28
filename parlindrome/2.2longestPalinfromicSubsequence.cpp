// 最长回文子序列(subsequence) - dp  l-516
// s.length⋿[1,1000]
#include <iostream>
#include <vector>
using namespace std;
int longestPalindromicSubsequence(string s);

int main()
{
    string s="bcbbb"; // input
    cout<<longestPalindromicSubsequence(s)<<endl; // output:4 "bbbb"
    return 0;
}

int longestPalindromicSubsequence(string s)
{
    int n=s.length();
    vector<vector<int>> dp(n,vector<int>(n)); // dp[i][j]:s[i,j] longestPalindromic subsequence
    for (int i=n-1; i>=0; --i) // [i,j]
    {
        dp[i][i]=1;
        for (int j=i+1; j<n; ++j)
        {
            if (s[i]==s[j])
                dp[i][j]=dp[i+1][j-1]+2;
            else
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
        }
    }
    return dp[0][n-1];
}