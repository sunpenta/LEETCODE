// 两数和相等的子数组-hash  l-2395
// 子数组:原数组中连续元素
#include <bits/stdc++.h>
using namespace std;
bool findSubarrays(vector<int>& nums);

int main()
{
    vector<int>nums={2,4,2}; // 输入
    cout<<boolalpha<<findSubarrays(nums)<<endl; // 输出:true 2+4=4+2
    system("pause");
}

bool findSubarrays(vector<int>& nums)
{
    int n=nums.size();
    unordered_set<int>sums;
    for (int i=1;i<n;i++)
    {
        int sum=nums[i-1]+nums[i];
        if (sums.count(sum))
            return true;
        sums.emplace(sum);
    }
    return false;
}