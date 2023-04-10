// 有效数字-分类  l-65
/* 有效数字（按顺序）可以分成以下几个部分：
1.一个小数或者整数
2.（可选）一个 'e' 或 'E',后面跟着一个整数
小数（按顺序）可以分成以下几个部分：
1.（可选）一个符号字符（'+' 或 '-'）
2.下述格式之一：
    1.至少一位数字，后面跟着一个点 '.'
    2.至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
    3.一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：
1.（可选）一个符号字符（'+' 或 '-'）
2.至少一位数字 */
#include <bits/stdc++.h>
using namespace std;
bool isNumber(string s);

int main()
{
    string s="1.3e12"; // 输入
    cout<<boolalpha<<isNumber(s)<<endl; // 输出:true
    system("pause");
}

bool isNumber(string s) // 原型，调用，定义函数名一致，写错isNummber
{
    bool numflag=false; bool dotflag=false; bool eflag=false;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]>='0' && s[i]<='9')
            numflag=true;
        else if (s[i]=='.' && !dotflag && !eflag)
            dotflag=true;
        else if ((s[i]=='e' || s[i]=='E') && !eflag && numflag)
        {
            eflag=true;
            numflag=false; // 重置，判断'e'后面数字
        }
        else if ((s[i]=='+' || s[i]=='-') && (i==0 || (s[i-1]=='e' || s[i-1]=='E')))
        {
            continue; // 正负号在首位，或在e后面
        }
        else
        {
            return false;
        }
    }
    return numflag;
}