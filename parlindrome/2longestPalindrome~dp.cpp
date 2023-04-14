// 最长回文子串-动态规划+分类 l-5
// 1 <= s.length <= 1000; s仅由数字和英文字母组成
#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s);

int main()
{
    string s=string(1,'a');
    cout<<s<<endl;

    /*
    string s = "babad"; // 输入
    cout <<longestPalindrome(s) << endl; // 输出:bab
    system("pause");
    */
}

string longestPalindrome(string s)
{
    int n = s.length();
    // 特殊情况：输入字符串只有一个字母
    if (n==1) return s; 

    int begin=0; // 最长回文串的起始下标
    int maxlen = 1; // 最大长度
    vector<vector<int>>dp(n, vector<int>(n,false)); // dp[i][j]:s[i,j]是否为回文串 
    for (int j=0;j<n;j++) // j:右边界
    {
        for (int i = 0; i < j; i++) // i:左边界
        {                      
            if (s[i] != s[j])
                dp[i][j] = false;
            else if (j-i<3) // (j-1)-(i+1)+1<2表示dp[i][j]的最大字串长度为1
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
