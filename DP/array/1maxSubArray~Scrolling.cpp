// 最大子数组和-动态规划->滚动数组  l-53
// 子数组元素连续; nums.length∈[1,1e5] -1e4 <= nums[i] <= 1e4
#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int>&nums);

int main()
{
    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4}; // 输入
    cout<<maxSubArray(nums)<<endl; // 输出:6 {4,-1,2,1}
    return 0;
}

int maxSubArray(vector<int>&nums)
{
    int pre=0; int maxsum=nums[0];
    for (int i=0;i<nums.size();i++)
    {
        pre=max(pre+nums[i],nums[i]); // 简化为pre，空间优化
        maxsum=max(maxsum,pre);
    }
    return maxsum;
}