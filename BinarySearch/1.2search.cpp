// 搜索旋转升序数组 - 二分查找 l-33
// 按升序排列，元素互不相同; 时间复杂度：O(logn)
#include<iostream>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target);

int main()
{ 
    vector<int> nums{4,5,6,7,0,1,2}; int target=0; // 输入
    cout<<search(nums,target)<<endl; // 输出：4
    return 0;
}

int search(vector<int>&nums,int target)
{
    int n=nums.size();
    int left=0, right=n-1;
    while (left<=right) // <=
    { 
        int mid=(left+right)/2;
        if (nums[mid]==target) return mid;
        
        // mid在左半段
        if (nums[mid]>=nums[0])
        {   
            if (target>=nums[0] && target<=nums[mid]) // target在前半升序段[0,mid]
                right=mid-1; 
            else 
                left=mid+1;
        }
        else // mid在右半段
        {         
            if (target>=nums[mid] && target<=nums[n-1]) // target在后半升序段[mid,n-1]
                left=mid+1;
            else 
                right=mid-1; 
        }
    }
    return -1; // 没找到target
}

