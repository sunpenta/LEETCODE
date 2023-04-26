// �ָ���Ĵ�-dp+dfs  l-131  -DP/string/1.2
// s.length��[1,16] 
#include <bits/stdc++.h>
using namespace std;
vector<vector<string>>partition(string s);

int main()
{
    string s="aab"; // ����
    vector<vector<string>>res=partition(s); // ���:{{"a","a","b"},{"aa","b"}}
    for (auto strs:res)
    {
        for (string str:strs)
            cout<<str<<" ";
        cout<<endl;
    }
    system("pause");
}

// �ָ���Ĵ�
void dfs(vector<vector<string>>& res,vector<string>& split,vector<vector<int>>&dp,string s,int index)
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
    // dpԤ����
    vector<vector<int>> dp(n,vector<int>(n,true)); // dp[i][j]:s[i,j]�Ƿ�Ϊ���Ĵ�;dp[i][i],dp[i][j](i>j)true
    for (int i=n-1;i>=0;i--) // ���ű���
    {
        for (int j=i+1;j<n;j++)
        {
            dp[i][j]=(s[i]==s[j]) && dp[i+1][j-1]; // ״̬ת�Ʒ���
        }
    }

    vector<vector<string>>res; vector<string>split;
    dfs(res,split,dp,s,0);
    return res;
}