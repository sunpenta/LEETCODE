// 分割回文串-dp+dfs  l-131  -DP/string/1.2
// s.length⋿[1,16] 
#include <iostream>
#include <vector>
using namespace std;
vector<vector<string>> partition(string s);

int main()
{
    string s="aab"; // input
    vector<vector<string>> res=partition(s); // output:{{"a","a","b"},{"aa","b"}}
    for (auto strs:res)
    {
        for (string str:strs)
            cout<<str<<" ";
        cout<<endl;
    }
    return 0;
}

// 压入1个[index,?]回文串
void dfs(vector<vector<string>>& res, vector<string>& split, vector<vector<int>>&dp, string s, int index)
{
    if (index==s.length())
    {
        res.emplace_back(split);
        return;
    }

    for (int i=index;i<s.length();i++)
    {
        if (dp[index][i])
        {
            split.emplace_back(s.substr(index,i-index+1));
            dfs(res,split,dp,s,i+1);
            split.pop_back();
        }
    }
}
vector<vector<string>>partition(string s)
{
    int n=s.length();
    // dp预处理
    vector<vector<int>> dp(n,vector<int>(n,true)); // dp[i][j]:s[i,j]是回文串; 默认[i,i]true
    for (int i=n-1;i>=0;i--) // [i,j]
    {
        for (int j=i+1;j<n;j++)
        {
            dp[i][j]=(s[i]==s[j]) && dp[i+1][j-1];
        }
    }

    vector<vector<string>> res; vector<string> split;
    dfs(res,split,dp,s,0);
    return res;
}