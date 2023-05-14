// 删除有序数组中的重复元素 - 原地 l-26
// -> 无重复数组个数k；nums[0,k-1] 是非重复数组
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