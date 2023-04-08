// 数字转换成罗马数字 l-12
#include <bits/stdc++.h>
using namespace std;
string int_to_roman(int num);

int main()
{
    int num=54; // 输入
    cout<<int_to_roman(num)<<endl; // 输出
    system("pause");
}

// 建立pair<int,string>数组
const pair<int, string> valueSymbols[] = 
{
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};
string int_to_roman(int num)
{
    string roman;
    for (auto &[value,symbol]: valueSymbols)
    {
        if (num>=value)
        {
            num-=value;
            roman+=symbol;
            if(num==0) break;
        }
    }
    return roman;
}