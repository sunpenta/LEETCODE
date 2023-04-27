// 最长回文子串 - 中心扩展法 l-5
// 1 <= s.length <= 1000; s仅由数字和英文字母组成
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
    //输入字符串只有一个字母
    if (n < 2) return s;
    // begin:最长回文子串的起始位置；len:当前回文子串长度; maxlen:当前最长 bias:从中心向两侧扩展的长度
    int begin=0,len=0,maxlen=0,bias=0;
    for (int i=0;i<n;i++)//i?
    {
        if (i>0 && s[i]==s[i-1]) continue;
        // 从当前位置向后找相同字符，作为回文串中心
        for (int j=i;j<n-1;j++)
        {
            if (s[j]==s[j+1])
                ++bias;
            else
                break;
        }
        // 第i轮循环可能找到的最长回文子串若不大于此前的最大值，则结束循环
        if (2*(n-i)-bias-1<=maxlen) break;

        // 从回文串的中心向两侧寻找
        for (len=1;len<i+1 && len<n-i-bias;len++)
        {
            if (s[len-i]!=s[len+i+bias])
                break;
        }

        if (2*len-bias-1>maxlen)
        {
            maxlen=2*len-bias-1;
            begin=i;
        }        
    }
    return s.substr(begin,maxlen);
}