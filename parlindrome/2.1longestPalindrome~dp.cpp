// 最长回文子串-动态规划+分类 l-5
// 1 <= s.length <= 1000; s仅由数字和英文字母组成
#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s);

int main()
{
    string s = "babad"; // 输入
    cout<<longestPalindrome(s)<<endl; // 输出:bab aba
    return 0;
}

string longestPalindrome(string s)
{
    int n = s.length();
    // 特殊情况：输入字符串只有一个字母
    if (n==1) return s; 

    int begin=0; // 最长回文串的起始下标
    int maxlen = 1; // 最大长度
    vector<vector<int>> dp(n, vector<int>(n,true)); // dp[i][j]:s[i,j]是否为回文串 
    for (int j=0; j<n; j++) // [i,j]
    {
        for (int i = 0; i < j; i++)
        {                      
            if (s[i]!=s[j])
                dp[i][j] = false;
            else if (j-i<3) // [i+1,j-1]没有字符，或有1个字符，(j-1)-(i+1)+1=j-i-1<=1, 即j-i<=2，
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
