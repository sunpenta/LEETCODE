// 验证回文串-存入新字符串  l-125
// 把所有大写字母转成小写字母，并移除所有非字母和数字字符，剩余字符串是回文串; s.length∈[1,2e5]
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s);

int main()
{
    string s="0P"; // 输入
    cout<<boolalpha<<isPalindrome(s)<<endl; // 输出:false
    system("pause");
}

bool isPalindrome(string s)
{
    int n=s.length();
    string news; // 存入新字符串
    for (char &ch:s)
    {
        if (isalnum(ch)) // 是字母或数字
            news+=tolower(ch);
    }
    string rs(news.rbegin(),news.rend()); // 反转
    return news==rs; // "0p!=p0"
}