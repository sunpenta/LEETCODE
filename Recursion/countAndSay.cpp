// 外观数列-递归   l-38  -YangHuiTriangle
#include <bits/stdc++.h>
using namespace std;
string countAndSay(int n);

int main()
{  
    int n=5; // 输入
    cout<<countAndSay(n)<<endl; // 输出
    system("pause");
}

string countAndSay(int n) 
{
    if (n==1) return "1";
        
    string str=""; // 初始化放在if后面，否则溢出
    string str_last=countAndSay(n-1); // 递归
    int len=1;
    for (int i=0;i<str_last.size();i++)
    {   
        if (str_last[i]==str_last[i+1])
            len++;
        else
        {
            str+=to_string(len)+str_last[i]; // +=省内存
            len=1;               
        }
    }
    return str;
}