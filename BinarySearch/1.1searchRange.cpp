// 在排序数组(非递减)中查找元素的第一个和最后一个位置-二分查找 l-34
// 有重复元素，时间复杂度：O(logn)
#include<bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target);

int main()
{
    vector<int>nums{5,7,7,8,8,10}; int target=8; // 输入
    vector<int>ans=searchRange(nums,target); // 输出:{3,4}
    cout<<ans[0]<<" "<<ans[1]<<endl;
    system("pause");
}

// 大于等于target的第一个元素下标
int binary_search(vector<int>&nums,int target)
{
    int left=0,right=nums.size();
    while (left<right)
    {
        int mid=(left+right)/2;
        if (nums[mid]>=target) 
            right=mid;
        else 
            left=mid+1;
    }
    return left;
}

vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int>ans(2,-1);
    int n=nums.size();
    //特殊情况：只有1个元素
    if (n==1)
        nums[0]==target?ans={0,0}:ans={-1,-1};

    //一般情况-二分查找   
    ans[0]=binary_search(nums,target); // 第1个
    ans[1]=binary_search(nums,target+1)-1; // 最后1个
    if (ans[0]==n || nums[ans[0]]!=target) // 找到最后未找到，或找到元素不等于target
        ans={-1,-1};
    return ans;
}
   

