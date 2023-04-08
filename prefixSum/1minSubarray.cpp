// 移除最短子数组后数组和能被p整除-前缀和+哈希  l-1590
// 子数组：原数组的连续元素
#include <bits/stdc++.h>
using namespace std;
int minSubarray(vector<int>&nums,int p);

int main()
{
    vector<int>nums={3,1,4,2}; int p=6; // 输入
    cout<<minSubarray(nums,p)<<endl; // 输出:1移除{4}
    system("pause");
}

// 数组和%p=子数组和%p，则移除子数组后能被p整除
int minSubarray(vector<int>&nums,int p)
{
    int x=0;
    for (auto num:nums)
        x=(x+num)%p; // 防止溢出
    if (x==0) return 0;

    int numRemove=nums.size(); // 移除元素个数
    unordered_map<int,int>index; // 前缀和的下标
    int y=0; index[0]=-1; // 前缀和
    for (int i=0;i<nums.size();i++)
    {
        y=(y+nums[i])%p;
        index[y]=i;
        int target=(y-x+p)%p; // y-x可能为负
        if (index.count(target)>0) // 最近的下标
              numRemove=min(numRemove,i-index[target]);
    } // (right-left)%p=x%p => (right-x)%p=left%p
    return numRemove==nums.size()?-1:numRemove; // 若移除整个数组，返回-1
}