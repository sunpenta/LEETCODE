// 最长回文子串 - dp l-5
// s.length⋿[1,1000]
#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s);

int main()
{
    string s = "babad"; // 输入
    cout<<longestPalindrome(s)<<endl; // 输出:bab
    return 0;
}

string longestPalindrome(string s)
{
    int n = s.length();
    if (n<2>) return s; 

    int begin=0, maxlen = 1; // 最长回文串的起始下标, 长度
    vector<vector<int>> dp(n, vector<int>(n,true)); // dp[i][j]:s[i,j]是否为回文串 
    for (int j=0; j<n; j++) // [i,j]
    {
        for (int i = 0; i < j; i++)
        {                      
            if (s[i]!=s[j])
                dp[i][j] = false;
            else if (j-i<3) // [i+1,j-1]没有字符，或有1个字符
                dp[i][j] = true;
            else
                dp[i][j] = dp[i + 1][j - 1];
                   
            if (dp[i][j] && (j-i+1)>maxlen) // 更新
            {
                maxlen=j-i+1;
                begin=i;  
            }
        }
    }
    return s.substr(begin, maxlen);
}
