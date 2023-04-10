// 搜索旋转排序数组-二分查找  l-81
// 非降序排列，数组有重复元素; -1e4 <= nums[i] <= 1e4
#include <bits/stdc++.h>
using namespace std;
bool search(vector<int>&nums,int target);

int main()
{
    vector<int>nums={1,1,2,1,1,1,1}; int target=2; // 输入
    cout<<search(nums,target)<<endl; // 输出:true
    system("pause");
}

bool search(vector<int>&nums,int target)
{
    int n=nums.size();
    if (n==1) return nums[0]==target;

    int left=0; int right=n-1; // 左右下标
    while (left<=right) // =
    {
        int mid=(left+right)/2;
        if (nums[mid]==target) return true;
        // 不能确定mid在左半段还是右半段
        if (nums[mid]==nums[left] && nums[mid]==nums[right]) // 不能连续等于
        {
            left++;
            right--; 
        }
        else if (nums[mid]>=nums[left]) // mid在左半段
        {
            if (target>=nums[left] && target<=nums[mid]) // 前半升序段[left,mid]
            {
                right=mid-1;      
            }
            else
            {
                left=mid+1;
            }
        }
        else
        {
            if (target>=nums[mid] && target<=nums[right]) // 后半升序段[mid,right]
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
    }
    return false;
}