// 给定行和、列和求可行矩阵-贪心  l-1605
# include <bits/stdc++.h>
using namespace std;
vector<vector<int>>retoreMatrix(vector<int>&rowSum,vector<int>&colSum);

int main()
{
    vector<int>rowSum={3,8}, colSum={4,7}; // 输入
    vector<vector<int>>matrix=retoreMatrix(rowSum,colSum); // 输出: {{3,0},{1,7}}
    for (auto row:matrix)
    {
        for (auto num:row)
            cout<<num<<" ";
        cout<<endl;
    }
    system("pause");
}

vector<vector<int>>retoreMatrix(vector<int>&rowSum,vector<int>&colSum)
{
    int m=rowSum.size(), n=colSum.size();
    vector<vector<int>>matrix(m,vector<int>(n)); // *设定空间大小*
    int i=0,j=0; // 横纵坐标
    while (i<m && j<n)
    {
        matrix[i][j]=min(rowSum[i],colSum[j]); // 取最小值
        rowSum[i]-=matrix[i][j];
        colSum[j]-=matrix[i][j];
        if (rowSum[i]==0)
            i++;
        if (colSum[j]==0)
            j++;
    }
    return matrix;
}