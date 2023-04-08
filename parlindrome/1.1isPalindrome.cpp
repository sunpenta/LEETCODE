// 验证回文数-分类  l-9
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int x);

int main()
{
    int x = 121; // 输入
    cout<<boolalpha<<isPalindrome(x)<<endl; // 输出:true
    system("pause");
}

bool isPalindrome(int x)
{
    // 特殊情况：负数,10的倍数不是回文数
    if (x < 0 || (x%10==0 && x!=0)) return false;
    if (x < 10) 
        return true;

    int reverted = 0;
    int xx = x;
    while (xx)
    {
        int digit = xx % 10;
        xx/=10;
        reverted = reverted * 10 + digit;
    }
    return x == reverted;
}