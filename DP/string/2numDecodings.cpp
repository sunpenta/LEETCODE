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
    system("pause");
}

int numDecodings(string s)
{
    if (s[0]=='0') return 0; // 无前导0
    int n=s.length();
    vector<int>dp(n); // dp[i]:[0,i]字符串的编码方法
    dp[0]=1; // 边界
    for (int i=1;i<n;i++)
    {
        if (s[i]!='0')
            dp[i]=dp[i-1];
        if (s[i-1]!='0' && stoi(s.substr(i-1,2))<=26) // 前1位不为0(无前导0)；且该两位整数<=26(可解码为字母)
        {
            if (i>1) 
                dp[i]+=dp[i-2];
            else // i=1
                dp[i]+=1;
        }
    }
    return dp[n-1];
}