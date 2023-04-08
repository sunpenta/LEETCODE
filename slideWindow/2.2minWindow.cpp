// 最小覆盖字串-滑动窗口+数组 l-76
// 1 <= m, n <= 1e5
#include <bits/stdc++.h>
using namespace std;
string minWindow(string s,string t);

int main()
{
    string s="ADOBECODEBANC"; string t = "ABC"; // 输入
    cout<<minWindow(s,t)<<endl;
    system("pause");
}

// 字符串s包含字符串t
string minWindow(string s,string t)
{
    int n=s.length();
    // 维护need[]和needcnt
    int *need=new int[128]; // 字符串t中字符次数，下标是字符的ASCII
    int needcnt=t.length(); // 所需字符数
    for (auto ch:t)
    {
        need[ch]++;
    }
    int minlen=1e5, start=-1; // 最小覆盖子串的长度和开始下标
    int left=0, right=0; // 滑动窗口的左右下标
    while (right<n)
    {
        char ch=s[right];
        if (need[ch]>0)   
            needcnt--; // 所需字符减1
        need[ch]--; // 若值为负，则ch不在字符串t中

        if (needcnt==0) // 满足条件
        {
            char tmp=s[left];
            while (need[tmp]<0 && left<=right) // 缩小窗口,更新need[]
            {
                need[tmp]++;
                left++;
            }
            if (right-left+1<minlen) // 记录最小覆盖子串
            {
                minlen=right-left+1;
                start=left;
            }
            need[s[left]]++; // 左下标继续右移，不满足条件，寻找新的滑动窗口
            needcnt++;
            left++;
        }
        right++; // 右下标右移
    }
    return start==-1?string():s.substr(start,minlen);
}
