// 有效括号-栈 + hash l-20
#include <bits/stdc++.h>
using namespace std;
bool isValid(string s);

int main()
{
    string s="{()[()]}"; // 输入
    cout<<boolalpha<<isValid(s)<<endl; //输出布尔型:1
    system("pause");
}

//判断有效字符串
bool isValid(string s)
{
    int n=s.size();
    //字符串为大小为奇数时，输出false
    if (n%2==1) return false;
    // 键为右括号，值为左括号
    unordered_map<char,char> pairs=
    {
        {')','('},
        {']','['},
        {'}','{'},
    };

    stack<char> stk; //建立栈,存char
    for (char ch: s) //遍历字符串s中的字符
    {    // ch是右括号
        if (pairs.count(ch)) // count()内是键
        {  // 当前左括号数必大于右括号数，因此栈必不为空
           if (stk.empty() || stk.top()!=pairs[ch])
                return false; //栈为空或栈顶元素不是对应左括号，输出false
            stk.pop(); // 一对括号匹配，栈顶元素出栈  
        }
        else //字符ch是左括号，入栈
            stk.push(ch);     
    }
    //若栈为空，是有效括号
    return stk.empty(); 
}