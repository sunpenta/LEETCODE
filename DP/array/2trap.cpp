// 接雨水-动态规划  l-42  -stack|-double_ptr
// 1 <= n <= 2 * 1e4; 0 <= height[i] <= 1e5
#include <bits/stdc++.h>
using namespace std;
int trap(vector<int>&heights);

int main()
{
    vector<int>heights={0,1,0,2,1,0,1,3,2,1,2,1}; // 输入
    cout<<trap(heights)<<endl; // 输出:6
    return 0;
}

int trap(vector<int>&heights)
{
    int n=heights.size();
    if (n<=2) return 0;
    vector<int>leftmax(n);
    vector<int>rightmax(n);

    // 左边最高[0,i]
    leftmax[0]=heights[0]; 
    for (int i=1;i<n;++i) // 下标从1开始
        leftmax[i]=max(leftmax[i-1],heights[i]);
    // 右边最高[i,n-1]
    rightmax[n-1]=heights[n-1];
    for (int i=n-2;i>=0;--i) // 下标从n-2开始
        rightmax[i]=max(rightmax[i+1],heights[i]);
        
    int ans=0; // 接水量
    for (int i=0;i<n;++i)
        ans+=min(rightmax[i],leftmax[i])-heights[i]; // 取最小值
    return ans;
}