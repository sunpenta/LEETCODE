// 简化路径-栈+字符流  l-71
/* 始终以斜杠 '/' 开头。
   两个目录名之间必须只有一个斜杠 '/' 。
   最后一个目录名（如果存在）不能 以 '/' 结尾。
   此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）
   (一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）)
*/
#include <bits/stdc++.h>
using namespace std;
string simplifyPath(string path);

int main()
{
    string path="/a//.././c/"; // 输入
    cout<<simplifyPath(path)<<endl; // 输出:"/c"
    system("pause");
}

string simplifyPath(string path)
{
    for (int i=0;i<path.size();i++) // 用for不用while
    {
        if (path[i]=='/') // 把所有'/'换成空格
            path[i]=' ';
    }
    stringstream os(path); // 用字符流把字符串分割为单词
    stack<string>sk;
    string str;
    while (os>>str) // 从os对象读取字符串str
    {   // 当/之间的字符串不是.或..即字母时
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