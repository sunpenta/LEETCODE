// 接雨水-双指针  l-42 -DP/vector/2|-stack/2
// 1 <= n <= 2e4; 0 <= height[i] <= 1e5
#include <bits/stdc++.h>
using namespace std;
int trap(vector<int>&heights);

int main()
{
    vector<int>heights={0,1,0,2,1,0,1,3,2,1,2,1}; // 输入
    cout<<trap(heights)<<endl; // 输出:6 {0,0,1,0,1,2,1,0,0,1,0,0}
    system("pause");
}

int trap(vector<int>&heights)
{
    int n=heights.size();
    if (n<=2) return 0;

    int ans=0; // 接水量
    int left=0; int right=n-1; // 左右下标
    int leftmaxh=0; int rightmaxh=0; // 左右柱子最高高度
    while (left<right)
    {
        leftmaxh=max(leftmaxh,heights[left]); // 更新左右最高高度
        rightmaxh=max(rightmaxh,heights[right]);
        if (heights[left]<heights[right])
        {
            ans+=leftmaxh-heights[left];
            ++left;
        }
        else
        {
            ans+=rightmaxh-heights[right];
            --right;
        }
    }
    return ans;
}