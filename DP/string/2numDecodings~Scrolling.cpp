// 解码方法 - 动态规划+分类+滚动数组  l-91
#include <iostream>
#include <vector>
using namespace std;
int numDecodings(string s);

int main()
{
    string s="120303113"; // 输入
    cout<<numDecodings(s)<<endl; // 输出：0
    system("pause");
}

int numDecodings(string s)
{
    if (s[0]=='0') return 0; // 无前导0
    int pre=1, cur=1; // dp[-1]=dp[0]=1
    for (int i=1;i<s.length();i++)
    {
        int tmp=cur;
        if (s[i]=='0') // 当前值'0'
        {
            if (s[i-1]=='1' || s[i-1]=='2')
                cur=pre;
            else
                return 0;
        }
        else if (s[i-1]!='0' && (10*(s[i-1]-'0')+(s[i]-'0'))<=26)
            cur+=pre;
        pre=tmp;
    }
    return cur;
}