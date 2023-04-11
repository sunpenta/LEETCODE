// 最大子数组和-动态规划  l-53  -hash/1,2|-prefixSum/1,2
// 子数组：元素连续; nums.length∈[1,1e5], -1e4 <= nums[i] <= 1e4
#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int>&nums);

int main()
{
    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4}; // 输入
    cout<<maxSubArray(nums)<<endl; // 输出:6 {4,-1,2,1}
    system("pause");
}

//  带上你累赘就丢掉
int maxSubArray(vector<int>&nums)
{
    int n=nums.size();
    vector<int>dp(n,INT_MIN); // dp[i]:[?,i]的最大数组和
    dp[0]=nums[0];
    int maxsum=INT_MIN;
    for (int i=1;i<n;i++)
    {
        dp[i]=max(dp[i-1]+nums[i],nums[i]);
        maxsum=max(maxsum,dp[i]);
    }
    return maxsum;
}