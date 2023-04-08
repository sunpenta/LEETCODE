// 删除最短子数组后剩余数组有序-双指针  l-1574  -DP/vector/1|prefixSum
// nums.length∈[1,1e5]
#include <bits/stdc++.h>
using namespace std;
int findShortestSubarray(vector<int>& nums);

int main()
{
    vector<int>nums={1,2,2,2,3,1,7,5,1,2,2,2,2,5,6}; // 输入
    cout<<findShortestSubarray(nums)<<endl; // 输出:5 剩余数组:{1,2,2,2,2,2,2,2,5,6}
    system("pause");
}

int findShortestSubarray(vector<int>& nums)
{
    int n=nums.size();
    int left=0, right=n-1;

    while (right>=0 && nums[right-1]<=nums[right])
        --right;
    if (right==0) return 0; // 原数组有序
    int ans=right; // 删除[0,right-1]

    for (left=0;left==0 || nums[left-1]<=nums[left];left++)
    {
        while (right<n && nums[left]>nums[right]) 
            ++right;
        ans=min(ans,right-left-1); // 删除(left,right)
    }
    return ans;
}