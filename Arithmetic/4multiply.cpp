// 字符串相乘-模拟 l-43
// 不能转换整数；1 <= num1.length, num2.length <= 200; num1 和 num2 只能由数字组成
#include <bits/stdc++.h>
using namespace std;
string multiply(string num1, string num2);

int main()
{
    string num1="123"; string num2 = "456"; // 输入
    cout<<multiply(num1,num2)<<endl; // 输出
    system("pause");
}

// 边转换，边乘，边加
string multiply(string num1,string num2)
{
    // 特殊情况：0乘任何数为0
    if (num1=="0" || num2=="0") return "0";

    int m=num1.size(); int n=num2.size();
    vector<int>sum(m+n,0);//存放各位相乘相加结果
    for (int i=0;i<m;i++)
    {
        int x=num1[i]-'0';//转换数字
        for (int j=0;j<n;j++)
        {
            int y=num2[j]-'0';
            sum[i+j+1]+=x*y;
        }
    }
    // 进位，统一成个位数
    for (int i=m+n-1;i>0;i--) //此处没有等于号，i!=0
    {
        sum[i-1]+=sum[i]/10;
        sum[i]%=10;
    }

    string ans="";
    int index= sum[0]==0?1:0; // 去除首位0
    for (int i=index;i<m+n;i++) // 转换成字符
    {
        ans+=(sum[i]+'0'); //有括号    
    }
    return ans;
}
