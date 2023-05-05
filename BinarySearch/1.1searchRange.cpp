// 在排序数组(非递减)中查找元素的第一个和最后一个位置 - Binary Search  l-34
// 有重复元素; 若未找到target,返回{-1,-1}; 时间复杂度：O(logn)
#include<iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target);

int main()
{
    vector<int>nums{5,7,7,8,8}; int target=8; // 输入
    vector<int>ans=searchRange(nums,target); // 输出:{3,4}
    cout<<"("<<ans[0]<<", "<<ans[1]<<")"<<endl;
    return 0;;
}

// 大于等于target的第一个元素下标,即lower_bound()
int binary_search(vector<int>& nums, int target)
{
    int left=0, right=nums.size();
    while (left<right)
    {
        int mid=(left+right)/2;
        if (nums[mid]>=target) // [left,target,mid,right] 
            right=mid;
        else 
            left=mid+1;
    }
    return left;
}

vector<int> searchRange(vector<int>& nums, int target)
{  
    int n=nums.size();
    if (n==1 && nums[0]==target)  return {0,0};

    vector<int> ans(2);
    ans[0]=binary_search(nums,target); // 第1个
    ans[1]=binary_search(nums,target+1)-1; // 最后1个
    if (ans[0]<n && nums[ans[0]]==target) 
        return ans;
    return {-1,-1};
}