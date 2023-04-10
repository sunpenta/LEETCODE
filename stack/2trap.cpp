// 接雨水-单调递减栈  l-42 -double_ptr -dp
#include <bits/stdc++.h>
using namespace std;
int trap(vector<int>&heights);

int main()
{
    vector<int>heights={0,1,0,2,1,0,1,3,2,1,2,1}; // 输入
    cout<<trap(heights)<<endl; // 输出
    system("pause");
}

int trap(vector<int>&heights)
{
    int n=heights.size();
    if (n<=2) return 0;

    int ans=0; // 接水量
    stack<int>sk; // 单调递减；依次存储左边，凹槽
    sk.push(0); // 存下标0
    
    for (int i=1;i<n;++i) // 从1开始
    {
        while (!sk.empty() && heights[i]>heights[sk.top()]) // 判空
        {
            int mid=heights[sk.top()]; // 凹槽下标
            sk.pop();
            int height,width;
            if (!sk.empty()) // 判空
            {
                height=min(heights[i],heights[sk.top()])-heights[mid];
                width=i-sk.top()-1; // sk.top():左柱下标
                ans+=height*width;
            }
        }
        sk.push(i);
    }
    return ans;
}