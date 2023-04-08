// 罗马数字转换成数字-哈希表 l-13
#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<char, int> valueSymbols = 
    {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1},
    };
    int num=0; //不赋值结果出错
    string s = "III";
    for (int i = 0; i < s.size(); i++)
    {

        if (valueSymbols[s[i]]< valueSymbols[s[i + 1]])
        {
            num -= valueSymbols[s[i]];
        }
        else
        {
            num += valueSymbols[s[i]];
        }
    }
    //输出
    cout << num << endl;
    system("pause");
}