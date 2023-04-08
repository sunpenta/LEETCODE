// 字典序元音字符串的组合数-dp  l-1641
// 字符串长度为n,仅由元音(a,e,i,o,u)组成，按字典序排列; 元素可重复使用; n∈[1,50]
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int countVowelStrings(int n);

int main()
{
    int n=3; // 输入
    cout<<countVowelStrings(n)<<endl; // 输出
    system("pause");
}

int countVowelStrings(int n)
{
    vector<int>dp(5,1); // dp[i]:以i为结尾的字符串数; 0:a 1:e 2:i 3:o 4:u
    for (int i=1;i<n;i++) // i:字符串长度-1
    {
        for (int j=1;j<5;j++)
        {
            dp[j]+=dp[j-1];
        }
    }
    return accumulate(dp.begin(),dp.end(),0);
}