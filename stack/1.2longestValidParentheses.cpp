// 最长有效括号长度-栈  l-32
// 栈为空，当前索引为不匹配的右括号；栈不为空，栈内存最后一个未匹配右括号索引
#include <bits/stdc++.h>
using namespace std;
int longestValidParentheses(string s);

int main()
{
    string s = ")()())()"; // 输入
    cout<<longestValidParentheses(s)<<endl; // 输出
    system("pause");
}

int longestValidParentheses(string s)
{
    int len = 0;    // 有效括号长度
    stack<int> stk; // 建立栈，存储索引int
    stk.push(-1);  // 索引为0时，避免栈为空
    // 从左往右遍历s
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') 
            stk.push(i); //左括号的索引
        else
        {
            stk.pop();  // 出栈
            if (stk.empty()) 
                stk.push(i);  // 最后一个未匹配右括号的索引
            else 
                len = max(len, i - stk.top());
        }
    }
    return len;
}