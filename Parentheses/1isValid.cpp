// 有效括号-栈+哈希表 l-20
#include <bits/stdc++.h>
using namespace std;
bool isValid(string s);

int main()
{
    string s="{()[()]}"; // 输入
    cout<<boolalpha<<isValid(s)<<endl; // 输出:true
    system("pause");
}

bool isValid(string s)
{
    int n=s.size();
    // 字符串为大小为奇数时，输出false
    if (n%2==1) return false;

    unordered_map<char,char> pairs= // <right，left>
    {
        {')','('},
        {']','['},
        {'}','{'},
    };

    stack<char> stk; 
    for (char ch: s)
    {   
        if (pairs.count(ch)) // ch是右括号
        {  
           if (stk.empty() || stk.top()!=pairs[ch]) // 当前左括号数必大于右括号数，因此栈必不为空
                return false; // 栈为空, 或栈顶元素!=对应左括号，输出false
            stk.pop(); // 一对括号匹配，左括号出栈  
        }
        else // ch是左括号，入栈
            stk.push(ch);     
    }
    return stk.empty(); // 若栈为空，left==right,是有效括号
}