// 二分查找 - 双指针  l-704
// 时间复杂度:O(logn) 空间复杂度：O(n)
# include<iostream>
# include<vector>
using namespace std;
int search(vector<int>& nums, int target);

int main()
{
    vector<int> nums={-1,0,3,5,9,12}; int target=9; // input
    
}

int search(vector<int>& nums, int target)
{
    int i=0, j=nums.size()-1;
    while (i<=j)
    {
        int mid=(left+right)/2;
        if (nums[mid]==target)
            return mid;
        else if (nums[mid]<target)
            left=mid+1;
        else
            right=mid-1;
    }
    return -1;
}