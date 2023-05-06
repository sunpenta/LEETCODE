// 杨辉三角 - dp  l-118
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
    vector<vector<int>>res;
    for (int i=0;i<numRows;i++) // 填充res的每一行
        //res[i]=vector<int>(i+1,1); 
        res.emplace_back(vector<int>(i+1,1)); // 更快
    
    for (int i=0;i<numRows;i++) // 行
    {
        for (int j=1;j<i;j++)
            res[i][j]=res[i-1][j-1]+res[i-1][j];
    }
    return res;
}