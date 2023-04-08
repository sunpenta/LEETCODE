// 无重复字符的最长子串-滑动窗口 l-3
#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s);

int main()
{
    string s = "abcabcbb"; // 输入
    cout<<lengthOfLongestSubstring(s)<<endl; // 输出:abc 3
    system("pause");
}

int lengthOfLongestSubstring(string s)
{
    int n=s.size();
    // start:无重复子串起始下标；end:无重复子串结束下标；len:当前无重复子串长度；maxlen:最长
    int start=0,end=0,len=0,maxlen=0;
    char tmp; // 存放无重复子串结尾字符的下一个字符
    while (end<n)
    {
        tmp=s[end];
        // s[start,end)中存在s[end]，更新start,len
        for (int i=start;i<end;i++)
        {
            if (s[i]==tmp)
            {
                start=i+1; // 不是start++
                len=end-start; // 去掉重复字符后，更新len [start,end)
                break; 
            }
        }
        end++; // 结尾下标加1
        len++; // 当前长度加1
        maxlen=max(maxlen,len); // 更新最长
    }
    return maxlen;   
}
