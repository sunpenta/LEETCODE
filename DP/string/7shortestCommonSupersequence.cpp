// 最短公共超序列-dp  l-1092
// 子序列; str1.length,str2.length∈[1,1000]
#include <iostream>
#include <vector>
using namespace std;
string shortestCommonSupersequence(string str1,string str2);

int main()
{
    string str1="abac", str2 = "cab"; // 输入
    cout<<shortestCommonSupersequence(str1,str2)<<endl; // 输出:"cabac"
    system("pause");
}

string shortestCommonSupersequence(string str1,string str2)
{
    int m=str1.length(), n=str2.length();
    vector<vector<int>>dp(m+1,vector<int>(n+1)); // dp[i][j]:str1[i,m-1]和str2[j,n-1]的最短公共超序列长度
    // 边界
    for (int i=0;i<m;i++) // str2为空
        dp[i][n]=m-i;
    for (int i=0;i<n;i++) // str1为空
        dp[m][i]=n-i;
    
    for (int i=m-1;i>=0;i--)
    {
        for (int j=n-1;j>=0;j--)
            if (str1[i]==str2[j])
                dp[i][j]=dp[i+1][j+1]+1;
            else
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])+1;
    }

    string res="";
    int t1=0,t2=0; // str1,str2的下标
    while (t1<m && t2<n)
    {
        if (str1[t1]==str2[t2])
        {
            res+=str1[t1];
            t1++,t2++;
        }
        else if (dp[t1][t2]==dp[t1+1][t2]+1)
        {
            res+=str1[t1];
            t1++;
        }
        else if (dp[t1][t2]==dp[t1][t2+1]+1)
        {
            res+=str2[t2];
            t2++;
        }
    }
    if (t1<m) // str1没遍历完
        res+=str1.substr(t1);
    else if (t2<n) // str2没遍历完
        res+=str2.substr(t2);
    return res;
}