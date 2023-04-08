// 杨辉三角-递归  l-119
#include <bits/stdc++.h>
using namespace std;
vector<int>getRow(int rowIndex); // 生成第rowIndex行

int main()
{
    int rowIndex=4; // 输入:从0开始
    vector<int>res=getRow(rowIndex); // 输出
    for (auto num:res)
        cout<<num<<" ";
    system("pause");
}

vector<int>getRow(int rowIndex)
{
    vector<int>res(rowIndex+1,1); // 用1填充
    if (rowIndex==0) return {1};
    vector<int>last=getRow(rowIndex-1); // 上一行
    for (int i=1;i<rowIndex;i++)
        res[i]=last[i-1]+last[i];
    return res;
}