// 简化路径 - stringstream + stack  l-71
/* 规范路径：
    以'/' 开头。
    两个目录名之间只有1个'/'
    不能 以 '/' 结尾（如果存在最后1个目录）
    不含 '.', '..'
    . :当前目录；.. :返回到上一级目录
*/
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;
string simplifyPath(string path);

int main()
{
    string path="/a//.././c/"; // input
    cout<<simplifyPath(path)<<endl; // output:"/c"
}

string simplifyPath(string path)
{
    for (char& ch:path) // 用for不用while
    {
        if (ch=='/') ch=' '; // 把所有'/'换成空格
    }

    stringstream ss(path); // 把path分割为单词
    stack<string> sk;
    string str;
    while (ss>>str) // 从os对象读取字符串str
    {
        if (str!="." && str!="..") // 注意格式" ",不是字符' '
            sk.push(str);
        else if (str==".." && !sk.empty()) // 已忽略"."
            sk.pop(); // 当/之间的字符串是..且前面有东西
    }
    string s; // 简化后
    while (!sk.empty())
    {
        s='/'+sk.top()+s;  // 注意顺序LIFO
        sk.pop();
    }
    if (s!="") return s;
    return "/";
}