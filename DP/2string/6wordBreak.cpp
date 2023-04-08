// 单词拆分-dp  l-139
// 字典中的单词可不用完，可重复使用
#include <iostream>
#include <vector>
using namespace std;
bool wordBreak(string s,vector<string>& wordDict);

int main()
{
    string s="catsandog"; vector<string>wordDict={"cats","dog","sand","and","cat"}; // 输入
    cout<<boolalpha<<wordBreak(s,wordDict)<<endl; // 输出:false
    system("pause");
}

bool wordBreak(string s,vector<string>& wordDict)
{
    int n=s.length();
    vector<bool>dp(n+1); // dp[i]:s[0,i)是否可用dict拼接
    dp[0]=true; // 空字符串
    for (int i=1;i<=n;i++) // 边界==n
    {
        for (string word:wordDict)
        {
            int len=word.length();
            if (i>=len && s.substr(i-len,len)==word) // *i>=len条件在前*
                dp[i]=dp[i] || dp[i-len];
        }
    }
    return dp[n];
}