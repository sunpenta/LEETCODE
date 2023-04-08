// 杨辉三角-递归  l-118
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>generate(int numRows); // 生成前numRows行

int main()
{
    int numRows=4; // 输入:从0开始
    vector<vector<int>>res=generate(numRows); // 输出
    for (auto row:res)
    {
        for (auto num:row)
            cout<<num<<" ";
        cout<<endl;
    }  
    system("pause");
}

vector<vector<int>>generate(int numRows)
{
    if (numRows==1) return {{1}};
    vector<vector<int>>last=generate(numRows-1);
    vector<int>lastRow=last.back();
    vector<int>curRow(numRows,1);
    for (int i=1;i<numRows-1;i++)
        curRow[i]=lastRow[i-1]+lastRow[i];
    last.emplace_back(curRow);
    return last;
}