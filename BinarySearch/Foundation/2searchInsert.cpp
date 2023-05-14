// 搜索插入位置  l-35
// -> >=目标元素的第1个位置；原数组升序排列，不含重复元素
// 时间复杂度:O(logn) 空间复杂度:O(1)
#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int>& nums, int target);

int main()
{
    vector<int> nums={2,3,5,7,8,9}; int target=6; // input
    int res=searchInsert(nums,target);
    cout<<res<<endl; // output:3
    return 0;
}

int searchInsert(vector<int>& nums, int target)
{
    int left=0, right=nums.size()-1;
    while (left<=right) // [left,right]
    {
        int mid=(left+right)/2;
        if (nums[mid]==target)
            return mid;
        else if (nums[mid]<target) // [left,mid,target,right]
            left=mid+1;
        else
            right=mid-1; // [left,target,mid,right]
    }
    return left;
}
