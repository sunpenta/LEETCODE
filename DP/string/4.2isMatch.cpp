// 正则表达式匹配-动态规划+分类  l-10
// '.' 匹配任意单个字符；'*' 匹配零个或多个前面的那一个元素
#include <bits/stdc++.h>
using namespace std;
bool isMatch(string s,string p);

int main()
{
    string s="mississippi", p= "mis*is*p*."; // 输入
    cout<<boolalpha<< isMatch(s,p) <<endl; // 输出
    system("pause");
}

bool isMatch(string s,string p)
{
    int m = s.length(), n = p.length();
    // 判断i和j处的字符是否匹配，当j处为'.',或两个字符相等时，匹配lamada表达式,返回bool; 
    auto matches = [&](int i, int j)
    {
        if (i == 0) return false; 
        if (p[j - 1] == '.') return true;
        return s[i - 1] == p[j - 1];
    };

    vector<vector<int>> dp(m + 1, vector<int>(n + 1)); // dp[i][j]:s[0,i)和p[0,j)匹配
    dp[0][0] = true; // 两个空字符匹配
    for (int i = 0; i <= m; i++)
    {
        for (int j = 1; j <= n; j++) //?1
        {
            if (p[j - 1] == '*')  // 把*和它前面的一个字符看成整体
            {   // 若i-1和j-1不匹配
                dp[i][j] |= dp[i][j - 2]; // dp[i][j] =dp[i][j] | dp[i][j - 2]
                if (matches(i, j - 1))  
                    dp[i][j] |= dp[i - 1][j];
            }
            else if (matches(i, j))
                dp[i][j] |= dp[i - 1][j - 1];
        }
    }
    return dp[m][n];
}