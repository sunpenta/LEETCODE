// 最小覆盖字串-滑动窗口+map l-76
// 1 <= m, n <= 1e5 超时
#include <bits/stdc++.h>
using namespace std;
string minWindow(string s,string t);

int main()
{
    string s="ADOBECODEBANC"; string t = "ABC"; // 输入 // s="ab" t="a"
    cout<<minWindow(s,t)<<endl;
    system("pause");
}
// curmap是否包含targetmap
bool cover(unordered_map<char,int>&curmap,unordered_map<char,int>&targetmap)
{
    for (auto &kv:targetmap)
    {
        char ch=kv.first; int n=kv.second;
        if (curmap[ch]<n)
            return false;
    }
    return true;
}
// 字符串s包含字符串t
string minWindow(string s,string t)
{
    int m=s.length();
    unordered_map<char,int>targetmap; // 字符串t的字符到次数的映射
    for (auto ch:t)
    {
        targetmap[ch]++;
    }
    unordered_map<char,int>curmap;// 当前子串的字符到次数的映射
    int left=0, right=-1; // 滑动窗口左右下标
    int minlen=1e5, start=-1; // 最小覆盖子串的长度和起始下标
    while (right<m)
    {
        if (targetmap.count(s[++right])) // 当前字符在t中
        {
            curmap[s[right]]++; // 漏写s[],写错成curmap[right]++
        }
        while (cover(curmap,targetmap) && left<=right) // 满足条件;注意left可以=right
        {
            if (targetmap.count(s[left])) // 子串的第1个字符在t中
            {
                curmap[s[left]]--;
            }
            
            if (right-left+1<minlen) // 记录最小覆盖字串
            {
                minlen=right-left+1;
                start=left;
            }
            left++; // 缩小窗口
        }
    }
    return start==-1?string():s.substr(start,minlen);
}
