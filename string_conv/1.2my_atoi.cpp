// 数字字符串转整数-stringstream l-8
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "words and 987"; // 输入
    stringstream liu(s); // 输出：0
    int n = 0;
    liu >> n;
    cout << n << endl;
    system("pause");
}