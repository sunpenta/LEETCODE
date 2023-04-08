// 正则表达式匹配-动态规划+分类  l-44  -Greed/3
// '?' 可以匹配任何单个字符,'*' 可以匹配任意字符串（包括空字符串）
#include <bits/stdc++.h>
using namespace std;
bool isMatch(string s,string p);

int main()
{
    string s="mississippi", p="mis*is*p*?"; // 输入   
    cout<<boolalpha<< isMatch(s,p) <<endl; // 输出：true
    system("pause");
}

// p匹配s:包含特殊字符的p最后等于s
bool isMatch(string s,string p)
{
    int m=s.length(); int n=p.length(); 
    vector<vector<bool>>dp(m+1,vector<bool>(n+1)); // dp[i][j]:s的前i个字符串和p的前j的字符串匹配
    dp[0][0]=true; // 两个空字符串匹配
    // * 可以匹配任何字符串包括空字符串
    for (int i=1;i<=n;++i) // 第1行：注意起始下标1
    {
        if (p[i-1]=='*')
            dp[0][i]=true; // 空s匹配只有'*'的p
        else
            break;
    }

    for (int i=1;i<=m;++i)
    {
        for (int j=1;j<=n;++j)
        {   /* 当'*'为空字符时，j-1,如果dp[i][j-1]能匹配，那么dp[i][j]匹配
               当'*'为多字符时，i-1,如果dp[i-1][j]能匹配，那么dp[i][j]匹配 */
            if (p[j-1]=='*')
                dp[i][j]=dp[i][j-1] | dp[i-1][j];  // 按位或
            else if(p[j-1]=='?' || s[i-1]==p[j-1]) // 逻辑或
                dp[i][j]=dp[i-1][j-1];
        }
    }
    return dp[m][n];
}
