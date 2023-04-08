//跳跃最多次数-动态规划  l-45
//向左d;向右跳d;跳到j:arr[i]>arr[j]且arr[i]>arr[k] min(i, j) < k < max(i, j)
#include <bits/stdc++.h>
using namespace std;
int jump(vector<int>&nums,int d);

int main()
{
    vector<int>nums={7,1,7,1,7,1}; int d=1;//输入
    cout<<jump(nums,d)<<endl;//输出
    system("pause");
}

int jump(vector<int>&nums,int d)
{
    int n=nums.size();
    // 带原下标从小到大排序
    vector<pair<int,int>>sorted(n);
    for (int i=0;i<n;i++)
    {
        sorted[i]=pair<int,int>(i,nums[i]);
    }
    auto cmp=[&](const pair<int,int>&a,const pair<int,int>&b)
    {
        return a.second<b.second;
    };
    sort(sorted.begin(),sorted.end(),cmp);
    
    int count=1;//当前最多步数
    vector<int>dp(n,1);//dp[i]：从i跳最多步数
    for (auto num:sorted)
    {
        int cur=num.first;//当前下标
        //向右
        int next=cur+1;
        while (next-cur<=d && next<n && nums[next]<nums[cur])
        {
            dp[cur]=max(dp[cur],dp[next]+1);
            next++;
        }
        //向左
        next=cur-1;
        while (cur-next<=d && next>=0 && nums[next]<nums[cur])
        {
            dp[cur]=max(dp[cur],dp[next]+1);
            next--;
        }
        count=max(count,dp[cur]);
    }
    return count;
}