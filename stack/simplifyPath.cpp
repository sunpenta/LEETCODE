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
    while (ss>>str)
    {
        if (str!="." && str!="..") // note:" ",不是字符' '
            sk.push(str);
        else if (str==".." && !sk.empty()) // 返回上1级
            sk.pop();
    }
    if (sk.empty()) return "/";

    string res=""; // stack -> res
    while (!sk.empty())
    {
        string tmp=sk.top(); sk.pop();
        res='/'+tmp+res;  // note:LIFO     
    }
    return res;
}