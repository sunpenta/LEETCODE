// 搜索旋转排序数组 - binary search  l-81
// 含重复元素，非降序排列; length⋿[1,1e4]; 时间复杂度:O(logn)
#include <iostream>
#include <vector>
using namespace std;
bool search(vector<int>& nums, int target);

int main()
{
    vector<int>nums={1,1,2,1,1,1,1}; int target=2; // 输入
    cout<<boolalpha<<search(nums,target)<<endl; // 输出:true
    return 0;
}

bool search(vector<int>& nums, int target)
{
    int n=nums.size();
    if (n==1) return nums[0]==target;

    int left=0; int right=n-1; // [0,n-1]
    while (left<=right) // <=
    {
        int mid=left+(right-left)/2;
        if (nums[mid]==target) 
            return true; 
        if (nums[mid]==nums[left] && nums[mid]==nums[right]) // 不确定mid在左半段还是右半段,不能连续等于
        {
            left++;
            right--; 
        }
        else if (nums[mid]>=nums[left]) // mid在左半段[0,mid,|]
        {
            if (target>=nums[left] && target<=nums[mid]) // 前半升序段[0,target,mid,|]
            {
                right=mid-1;      
            }
            else
            {
                left=mid+1;
            }
        }
        else // [|,mid,n-1]
        {
            if (target>=nums[mid] && target<=nums[right]) // 后半升序段[|,mid,target,n-1]
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