// 只出现1次的数字-异或  l-136
// 只有1个元素出现1次，其余元素均出现两次; nums[i]∈[INT_MIN,INT_MAX]; 时间复杂度:O(n),空间复杂度:O(1)
#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums);

int main()
{
    vector<int>nums={2,2,3,3,1,4,4}; // 输入
    cout<<singleNumber(nums)<<endl; // 输出
    system("pause");
}

// num^0=num; num^num=0
int singleNumber(vector<int>& nums)
{
    int ans=0;
    for (auto &num:nums)
    {
        ans^=num; 
    }
    return ans;
}