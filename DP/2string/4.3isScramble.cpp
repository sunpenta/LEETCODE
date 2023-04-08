// 扰乱字符串-动态规划/记忆化搜索  l-87
// 1 <= s1.length <= 30
#include <bits/stdc++.h>
using namespace std;
bool isScramble(string s1,string s2);

int main()
{
    string s1="abcde", s2="caebd"; // 输入
    cout<<boolalpha<<boolalpha<<isScramble(s1,s2)<<endl; // 输出:false
    system("pause");
}

int dp[31][31][31];  // dp[i][j][k]:标记访问过的字符串；i：s1的起始下标;j：s1的结束下标;k:s2的开始下标
// s1[b1,e1]和s2[b2,e2]是否是扰乱字符
bool dfs(string &s1,int b1,int e1,string &s2,int b2,int e2)
{
    if (dp[b1][e1][b2]==2)
        return false;
    if (b1==e1 && s1[b1]==s2[b2]) // 只有1个字符，且s1,s2两个字符相等
        return true;
    for (int i=b1;i<e1;i++) // 分割位置
    {
        //if (dfs(s1,b1,i,s2,b2,b2+i-b1) && dfs(s1,i+1,e1,s2,e2-e1+i+1,e2))
        if(dfs(s1,b1,i,s2,b2,b2+i-b1) && dfs(s1,i+1,e1,s2,b2+i-b1+1,e2))
            return true;   
        //if (dfs(s1,b1,i,s2,e2-i+b1,e2) && dfs(s1,i+1,e1,s2,b2,b2+e1-i-1))
        //if(dfs(s1,b1,i,s2,e2-i+b1,e2) && dfs(s1,i+1,e1,s2,b2,e2-i+b1-1))
        if (dfs(s1,b1,i,s2,b2+e1-i,e2) && dfs(s1,i+1,e1,s2,b2,b2+e1-i-1))
            return true;
    }
    dp[b1][e1][b2]=2;
    return false;
}

bool isScramble(string s1,string s2)
{
    int n=s1.length();
    memset(dp,0,sizeof(dp)); // 设初始值0
    return dfs(s1,0,n-1,s2,0,n-1);  // [b1,e1]和[b2,e2]长度相等
}