// 移除最短子数组后数组和能被p整除-prefix sum + hash  l-1590
// 子数组：原数组元素连续; nums.length∈[1,1e5], nums[i]∈[1,1e9]
#include <bits/stdc++.h>
using namespace std;
int minSubarray(vector<int>&nums,int p);

int main()
{
    vector<int>nums={3,1,4,2}; int p=6; // 输入
    cout<<minSubarray(nums,p)<<endl; // 输出:1 移除{4}, sum{3,1,2}=6%6=0
    system("pause");
}

// 数组和%p=子数组和%p，则sum(nums)%p==0
int minSubarray(vector<int>&nums,int p)
{
    int n=nums.size(), need=0, cur=0;
    for (auto num:nums)
        need=(need+num)%p; // 防溢出
    if (need==0) return 0;

    int numRemove=nums.size();
    unordered_map<int,int> index; // <prefix sum%p, index> [0,index]
    index[0]=-1;
    for (int i=0;i<nums.size();i++)
    {
        cur=(cur+nums[i])%p;
        index[cur]=i;
        int target=(cur-need+p)%p; // 可能为负,[0,p)
        if (index.count(target)) // 最近的下标
              numRemove=min(numRemove,i-index[target]); // (index[target], i]
    } // (right-left)%p=x%p => (right-x)%p=left%p
    return numRemove<n?numRemove:-1; // 若移除整个数组，返回-1
}