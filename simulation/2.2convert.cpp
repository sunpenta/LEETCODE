// N字形变换-模拟法2：flag反复读取  l-6
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
    vector<string>res(numRows);
    int i=0; int flag=-1; // flag是个好东西
    for (auto ch:s)
    {
        if (i==0 || i==numRows-1) // *i==numRows-1*不是numsRows
            flag=-flag;
        res[i]+=ch;
        i+=flag;
    }
    string ans="";
    for (auto str:res)
    {
        ans+=str;
    } 
    return ans;
}