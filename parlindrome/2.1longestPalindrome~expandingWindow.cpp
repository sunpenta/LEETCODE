// 最长回文子串 - 中心扩展法(更快) l-5
// s.length⋿[1,1000]; 时间复杂度:O(n²)
#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s);

int main()
{
    string s = "babad"; // 输入
    cout <<longestPalindrome(s)<< endl; // 输出:bab
    return 0;
}

string longestPalindrome(string s)
{
    int n = s.size();
    if (n < 2) return s;

    int begin=0, maxlen=0;
    for (int i=0; i<n;)
    {
        if (n-i<=maxlen/2) break;
        int l=i, r=i; // [l,r]
        while (r<n-1 && s[r]==s[r+1])
            ++r; // 跳过重复元素
        i=r+1;
        while (r<n-1 && l>0 && s[l-1]==s[r+1])
        {
            --l; ++r;
        }
        if ((r-l+1)>maxlen)
        {
            begin=l;
            maxlen=r-l+1;
        }
    }
    return s.substr(begin,maxlen);
}