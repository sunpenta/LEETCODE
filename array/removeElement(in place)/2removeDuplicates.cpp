// 删除有序数组的重复元素 -  l-26
// -> 无重复元素个数k，原数组改变，前k个是无重复元素(原顺序不变)
#include <bits/stdc++.h>
using namespace std;
int deleteDuplicates(vector<int>& nums);

int main()
{
    vector<int> nums={0,0,1,1,1,2,2,3,3,4}; // 输入
    cout<<deleteDuplicates(nums)<<endl; // output: 5
    for (int num:nums) // 改变原数组
        cout<< num << " "; // 0 1 2 3 4
    return 0;  
}

int deleteDuplicates(vector<int>& nums)
{
    int n=nums.size(), index=1;
    for (int i=1; i<n; i++)
    {
        if (nums[i]!=nums[i-1]) 
            nums[index++]=nums[i];
    }
    return index;
}