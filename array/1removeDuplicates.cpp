// 删除有序数组中的重复项 - 新数组 l-26  -Linked List/delete/deleteDuplicates
// -> 无重复数组个数
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
    int n=nums.size();
    vector<int> res;
    for (int i=0;i<n;i++)
    {
        if (i>0 && nums[i]==nums[i-1]) 
            continue;
        res.emplace_back(nums[i]);
    }
    nums=res;
    return res.size();
}