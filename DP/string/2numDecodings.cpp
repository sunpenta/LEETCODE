// 解码方法 - 动态规划+分类  l-91   -DfsorRecursion\string\restoreAddresses
// 'A'->'1', ... ,'Z'->'26'
#include <iostream>
#include <vector>
using namespace std;
int numDecodings(string s);

int main()
{
    string s="120303113"; // 输入
    cout<<numDecodings(s)<<endl; // 输出：0
    return 0;
}

int numDecodings(string s)
{
    int n=s.length();
    vector<int> dp(n+1); // dp[i]:[0,i]字符串的编码方法
    dp[0]=1; // 边界
    for (int i=1; i<n; i++)
    {
        if (s[i]!='0')
            dp[i+1]=dp[i];
        if (s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6')) // 前1位不为0(无前导0)；且该两位整数<=26(可解码为字母)
        {
            dp[i]+=dp[i-2];
        }
    }
    return dp[n-1];
}