// 最长回文子串 - 中心扩展法(更快) l-5
// s.length⋿[1,1000]
#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s);

int main()
{
    string s = "babad"; // 输入
    cout <<longestPalindrome(s)<< endl; // 输出:bab
    system("pause");
}
// 假设s[i,j]都是连续相同字符,向两边扩展，直到s[i-k]!=s[i+k],那么s[i-k+1,i+k-1]是回文子串，此时长度len=j-i+2k-1
string longestPalindrome(string s)
{
    int n = s.size();
    if (n < 2) return s;

    int begin=0, maxlen=0;

    return s.substr(begin,maxlen);
}