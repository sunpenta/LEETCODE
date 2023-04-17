// 盛水最多的容器-双指针  l-11  -stack/3.1
// 2 <= n <= 1e5; 0 <= height[i] <= 1e4
#include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int>&heights);

int main()
{
    vector<int> height= {1,8,6,2,5,4,8,3,7}; // 输入
    cout<<maxArea(height)<<endl; // 输出:49 {8,6,2,5,4,8,3,7}
    return 0;
}

int maxArea(vector<int>&heights)
{
    int n = heights.size();
    int area=0, maxarea = 0; // 当前面积，最大面积
    
    int left = 0; int right = n - 1; // 左右下标
    while (left < right)
    {
        area = min(heights[left], heights[right]) * (right - left);
        maxarea = max(maxarea, area);
        if (heights[left] < heights[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return maxarea;
}