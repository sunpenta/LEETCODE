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
    vector<int> dp(n+1); // dp[i]: 前i个数即[0,i-1]的解码方法
    dp[0]=1; dp[1]=(s[0]!='0');
    for (int i=1; i<n; i++)
    {
        if (s[i]!='0')
            dp[i+1]=dp[i];
        if (s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6')) // 两位整数'1'-'26'
        {
            dp[i]+=dp[i-2];
        }
    }
    return dp[n-1];
}