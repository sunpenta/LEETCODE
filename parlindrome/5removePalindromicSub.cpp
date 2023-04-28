// 移除?次回文子序列 - brain test  l-1332
// 仅包括'a'和'b'; 只有1和2两个结果
#include <iostream>
using namespace std;
int removepalindromicSub(string s);

int main()
{
    string s="abbaaaab"; // input
    cout<<removepalindromicSub(s)<<endl; // output
    return 0;
}

int removepalindromicSub(string s)
{
    int n=s.length();
    for (int i=0,j=n-1; i<j; ++i,--j)
    {
        if (s[i]!=s[j])
            return 2;
    }
    return 1;
}