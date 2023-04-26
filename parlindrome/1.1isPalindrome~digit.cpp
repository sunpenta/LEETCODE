// 回文数 - 计算数字个位  l-9   -Arithmetic/addDigit
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int x);

int main()
{
    int x = 121; // 输入
    cout<<boolalpha<<isPalindrome(x)<<endl; // 输出:true
    return 0;
}

bool isPalindrome(int x)
{
    // 特殊情况：不是回文数：负数，或10的倍数（除0）
    if (x < 0 || (x%10==0 && x!=0)) return false;
    if (x < 10)  return true; // 个位数

    int reversed = 0;
    while (x>reversed)
    {   
        reversed = reversed* 10 + x % 10;
        x/=10;
    }
    return x == reversed;
}