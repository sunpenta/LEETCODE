// 搜索旋转数组-二分查找 l-33
// 按升序排列，元素互不相同; 时间复杂度：O(logn)
#include<bits/stdc++.h>
using namespace std;
int search(vector<int>&nums,int target);

int main()
{ 
    vector<int>nums{4,5,6,7,0,1,2}; int target=0; // 输入
    cout<<search(nums,target)<<endl; // 输出：4
    system("pause");
}

int search(vector<int>&nums,int target)
{
    int n=nums.size();
    int ans=-1; //输出索引
    // 特殊情况：数组只有1个元素
    if (n==1)
        return nums[0]==target?0:-1; // 注意双等号，单等号为赋值语句，恒为真

    // 一般情况：二分查找
    int left=0, right=n-1;
    while (left<=right) // 注意等号
    { 
        int mid=(left+right)/2;
        if (nums[mid]==target) return mid;
        
        // mid在左半段
        if (nums[mid]>=nums[0]) // 注意不等号方向
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

