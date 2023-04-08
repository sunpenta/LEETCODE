// 至少有1位重复数字-dp+位运算  l-1012
#include <bits/stdc++.h>
using namespace std;
int numDupDigitsAtMostN(int n);

int main()
{
    int n=100; // 输入:[1,...,100]
    cout<<numDupDigitsAtMostN(n)<<endl; // 输出:10
    system("pause");
}

int fact(int val) // 阶乘
{
    if (val==0 || val==1) return 1;
    return val*fact(val-1);
}

int A(int n,int m) // 排列数
{
    return fact(n)/fact(n-m);
}

int numDupDigitsAtMostN(int n)
{
    int total=0; // 不重复数的个数
    string nums=to_string(n);
    
    int len=nums.length(); // 位数
    vector<int>last(10,0); // 
    // 位数小于len
    for (int i=1;i<len;i++)
    {
        total+=A(9,i-1);
    }
    cout<<endl;
    // 位数等于len
    for (int i=0;i<len;i++)
    {
        int x=nums[i]-'0';
        for (int j=(i==0);j<x;j++)
        {
            if (last[j]) continue;
            total+=A(9-i,len-i-1);
        }
        if (++last[i]==2) break;
        if (i==len-1) total++;
    }
    return n-total;
}

