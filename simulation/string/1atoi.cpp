// 数字字符串转整数-分类模拟 l-8
#include <bits/stdc++.h>
using namespace std;
int atoi(string s);

int main()
{
    string s = "words and 987"; // 输入 
    cout<<atoi(s)<<endl; // 输出：0
    system("pause");
}

int atoi(string s)
{
    int res=0; // 整数部分
    int flag=1; // 默认为正
    int i=0; // 下标
    while (s[i]==' ') i++; // 读入字符串并丢弃无用前导空格
    if (s[i]=='-') flag=-1; // 先确定flag，不可与下一步颠倒
    if (s[i]=='+'||s[i]=='-') i++; // 读入正负号
    // 判断是否是数字，且未到结尾; 若未读入数字（即违法输入），则返回0
    while (s[i]>='0' && s[i]<='9' && i<s.size()) // 字符'0'-'9'，不要写错成数字
    {
        int r=s[i]-'0'; // 字符转成数字
        //处理溢出   -2147483648 2147483647
        if (res>INT_MAX/10 || (res==INT_MAX/10 && r>7)) 
            return flag>0? INT_MAX:INT_MIN;
        res=res*10+r;
        i++;
    }
    return flag>0?res:-res;
}