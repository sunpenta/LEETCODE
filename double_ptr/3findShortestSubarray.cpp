// ɾ������������ʣ����������-˫ָ��  l-1574  -DP/vector/1 | prefixSum
// nums.length∈[1,1e5]
#include <bits/stdc++.h>
using namespace std;
int findShortestSubarray(vector<int>& nums);

int main()
{
    vector<int>nums={1,2,2,2,3,1,7,5,1,2,2,2,2,5,6}; // input
    cout<<findShortestSubarray(nums)<<endl; // output:5 ʣ������:{1,2,2,2,2,2,2,2,5,6}
    return 0;
}

int findShortestSubarray(vector<int>& nums)
{
    int n=nums.size();
    int left=0, right=n-1;

    while (right>=0 && nums[right-1]<=nums[right])
        --right;
    if (right==0) return 0; // ԭ��������
    int ans=right; // ɾ��[0,right-1]

    for (left=0;left==0 || nums[left-1]<=nums[left];left++)
    {
        while (right<n && nums[left]>nums[right]) 
            ++right;
        ans=min(ans,right-left-1); // ɾ��(left,right)
    }
    return ans;
}