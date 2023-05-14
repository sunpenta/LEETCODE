// nextPermutation l-31
// 包含重复元素
#include<bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int>&nums);

int main()
{
    vector<int>nums{1,5,1}; //输入
    nextPermutation(nums); //输出
    for (auto num:nums) cout<<num<<" ";
    return 0;
}

void nextPermutation(vector<int>&nums)
{
    int i=nums.size()-2;//倒数第二个
    //从倒数第二个数向前遍历，找到较小的数
    while (i>=0 && nums[i]>=nums[i+1]) 
        i--;

    int j=nums.size()-1;//倒数第一个
    // 从倒数第一个数向前遍历，找到比nums[i]大的数
    if (i>=0) // 当nums={3,2,1},i=-1
    {  
        while (j>=0 && nums[i]>=nums[j]) // 等于号
            j--;
        swap(nums[i],nums[j]);//交换i和j两个位置的元素
    }
    reverse(nums.begin()+i+1,nums.end());//翻转从i+1到末尾的数组，使它从小到大排列
}