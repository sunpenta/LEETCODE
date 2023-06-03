// 缺失的第一个正数 - 哈希  l-41
// 时间复杂度:O(n), 空间复杂度:O(1)
#include <bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int>&nums);

int main()
{
    vector<int>nums{-1,-2,-60,1,2,43}; // 输入
    cout<<firstMissingPositive(nums)<<endl; // 输出:3
    system("pause");
}

int firstMissingPositive(vector<int>&nums)
{
    bool flag=true;
    int n=nums.size();
  
    for (int i=0; i<n; i++)
    {
        if (nums[i]==1) flag=false;
    }
    if (flag) return 1; // nums没1

    // nums范围内的正数：[1,n],在范围外的数置1
    for (int i=0; i<n; i++)
    {
        if (nums[i]<=0 || nums[i]>n) 
            nums[i]=1;
    }
    
    for (int i=0; i<n; i++)
    {
        int pos=nums[i]>0? nums[i]:-nums[i];
        nums[pos-1]=nums[pos-1]<0 ? nums[pos-1]:-nums[pos-1];
    }
    // 第一个大于0的数
    for (int i=0;i<n;i++)
    {
        if (nums[i]>0) 
            return i+1;
    }
    return n+1;
}