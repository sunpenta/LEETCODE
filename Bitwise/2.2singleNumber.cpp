// 只出现1次的数字-位运算  l-137
// 只1个元素出现1次，其余元素均出现三次;nums[i]∈[INT_MIN,INT_MAX]; 时间复杂度:O(n),空间复杂度:O(1)
#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums);

int main()
{
    vector<int>nums={2,2,2,1}; // 输入
    cout<<singleNumber(nums)<<endl; // 输出
    return 0;
}

// ans二进制第i位=所有元素第i位1的个数 mod 3
int singleNumber(vector<int>& nums)
{
    int ans=0;
    for (int i=0;i<32;i++) // i:倒着对32位二进制数编号
    {
        int total=0; // 第i位1的总个数
        for (int num:nums)
        {
            total+=(num>>i)&1; // 测试num第i位是1
        }
        cout<<i<<" "<<total<<endl;
        if (total%3)
        {
            ans|=(1<<i); 
        }
    }
    return ans;
}