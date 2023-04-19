// 外观数列 - Recursion   l-38  -YangHuiTriangle
#include <iostream>
using namespace std;
string countAndSay(int n);

int main()
{  
    int n=5; // 输入
    cout<<countAndSay(n)<<endl; // 输出: 111221  1 11 21 1211 111221
    return 0;
}

string countAndSay(int n) 
{
    if (n==1) return "1";
        
    string str=""; // 初始化放在if后面，否则溢出
    string pre_str=countAndSay(n-1); // 递归
    int len=1;
    for (int i=0; i<pre_str.size(); i++)
    {   
        if (pre_str[i]==pre_str[i+1])
            len++;
        else
        {
            str+=to_string(len)+pre_str[i]; // +=省内存
            len=1;            
        }
    }
    return str;
}