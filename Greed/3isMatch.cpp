// 正则表达式匹配 -贪心算法+分类 l-44
// '?' 可以匹配任何单个字符,'*' 可以匹配任意字符串（包括空字符串）
#include <bits/stdc++.h>
using namespace std;
bool isMatch(string s,string p);

int main()
{
    string s = "mississippi", p = "mis*is*p*?"; // 输入
    cout<<boolalpha<<isMatch(s,p)<<endl; // 输出:true
    system("pause");
}

bool isMatch(string s,string p)
{
    int i=0,j=0; // 字符串s和p遍历的当前下标
    int istar=-1,jstar=-1; // *的下标
    int m=s.size(),n=p.size();
    while (i<m)
    {
        if (j<n && (p[j]=='?' || p[j]==s[i]))
        {
            ++i;
            ++j;
        }
        else if (j<n && p[j]=='*')
        {
            istar=i;   // 记录遇到*的位置
            jstar=j++; // 忽略*?
        }
        else if (istar>=0) // 遇到过*，但此时不匹配且没有遇到*
        {
            i=++istar; // 回溯到istar+1,*代表多个字符，一直向前遍历，看是否匹配
            j=jstar+1; // 回溯到jstar+1
        }
        else  // 如果不匹配，且找不到下一个位置，那么false
            return false;
    }
    // 字符串s已经匹配完，此时p接下来必须全为*才能匹配
    while (j<n && p[j]=='*')  ++j;
    return j==n;
}