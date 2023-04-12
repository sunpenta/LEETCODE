// 柱状图中的最大矩形-单调递增栈  l-84
#include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int>&heights);

int main()
{
    vector<int>heights={2,1,5,6,2,3}; // 输入
    cout<<maxArea(heights)<<endl; // 输出:10
    system("pause");
}

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
        while (heights[i]<heights[sk.top()] && !sk.empty()) // while not if
        {
            int height=heights[sk.top()];
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