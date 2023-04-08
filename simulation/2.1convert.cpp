// N字形变换-模拟法1：找规律  l-6
// 1 <= s.length <= 1000; 1 <= numRows <= 1000; s由英文字母（小写和大写）、',' 和 '.' 组成
#include <bits/stdc++.h>
using namespace std;
string convert(string s,int numRows);

int main()
{
    string s="PAYPALISHIRING"; int numRows=3; // 输入
    cout<<convert(s,numRows); // 输出
    system("pause");
}

string convert(string s,int numRows)
{
    int n=s.length();
    string ans="";
    int t=2*(numRows-1); // 周期
    for (int i=0;i<numRows;i++) // 行
    {
        int j; // s的下标
        for (j=i;j<n;j+=t)
        {
            ans+=s[j]; // 周期内的第1个数
            if (i>0 && i<numRows-1 && j+t-2*i<n)
            {
                ans+=s[j+t-2*i]; // 除了第1和倒数第1行的中间行，周期的第2个数
            }
        }
    }
    return ans;
}