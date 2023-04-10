// 最大矩形-单调递增栈  l-85
// matrix[i][j] 为 '0' 或 '1'
#include <bits/stdc++.h>
using namespace std;
int maximalRectangle(vector<vector<char>>& matrix);

int main()
{
    vector<vector<char>>matrix={
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'},
    };  // 输入
    cout<<maximalRectangle(matrix)<<endl; // 输出:6
    system("pause");
}

// 柱形图的最大面积(同3.1)
int maxArea(vector<int>&heights)
{
    heights.insert(heights.begin(),0); // 前后哨兵
    heights.emplace_back(0);
    stack<int>sk; // 单调递增栈,存矩形左边下标
    sk.push(0);
    int n=heights.size();
    int maxarea=0, area=0;
    for (int i=0;i<n;i++) // 找到第1个比自己小的柱子
    {
        while (heights[i]<heights[sk.top()] && !sk.empty()) 
        {
            int height=heights[sk.top()]; // 矩形高
            sk.pop();
            if (!sk.empty())
            {
                area=height*(i-sk.top()-1); // (sk.top(),i)之间的矩形面积
                maxarea=max(maxarea,area);
            }
        }
        sk.push(i);
    }
    return maxarea;
}

int maximalRectangle(vector<vector<char>>& matrix)
{
    int m=matrix.size(), n=matrix[0].size();
    vector<vector<int>>heightss(m,vector<int>(n)); // 每个矩阵坐标的柱子高度
    for (int i=0;i<n;i++)
    {
        if (matrix[0][i]=='0')
            heightss[0][i]=0;
        else
            heightss[0][i]=1;
    }

    for (int i=1;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (matrix[i][j]=='0')
                heightss[i][j]=0;
            else
                heightss[i][j]=heightss[i-1][j]+1;
        }
    }
    int maxarea=0,curarea=0;
    for (int i=0;i<m;i++)
    {
        curarea=maxArea(heightss[i]);
        maxarea=max(maxarea,curarea);
    }
    return maxarea;
}

