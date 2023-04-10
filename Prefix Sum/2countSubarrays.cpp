// 统计中位数为k的子数组-prefix sum + hash  l-2488
// 中位数：数组经排序, 位于中间或中间偏左的元素.例{2,1,3,4}中位数是2
#include <bits/stdc++.h>
using namespace std;
int countSubarrays(vector<int>&nums,int k);

int main()
{
    vector<int>nums={3,2,1,4,5}; int k=4; // 输入
    cout<<countSubarrays(nums,k)<<endl; // 输出:3 {4}{4,5}{1,4,5}
    system("pause");
}

// num正数->1，负数->-1，0->0
int sign(int num)
{
    if (num==0) return 0;
    return num>0?1:-1;
}

// k(中位数)在中间，>k的元素数 = <k的元素数；k在中间偏左，>k的元素数 = <k的元素数+1
int countSubarrays(vector<int>&nums,int k)
{
    auto it=find(nums.begin(),nums.end(),k);
    int kIndex=it-nums.begin(); // k的下标

    unordered_map<int,int>counts; // <sum,counts>:<[0,i]大于k的元素数,次数>
    counts[0]=1; // k
    int sum=0, ans=0;
    for (int i=0;i<nums.size();i++) 
    {
        sum+=sign(nums[i]-k); 
        if (i<kIndex)
            counts[sum]++; // left=i+1 
        else
        {
            int pre0=counts[sum]; // right=i (left,i]
            int pre1=counts[sum-1];
            ans+=pre0+pre1;
        }
    }
    return ans;
}