// 和有上限的最长子序列  l-2389 
// nums.length∈[1,1000]
#include <bits/stdc++.h>
using namespace std;
vector<int>answerQueries(vector<int>& nums,vector<int>& queries);

int main()
{
    vector<int>nums={4,5,2,1}, queries={3,10,21}; // 输入
    vector<int>ans=answerQueries(nums,queries); // 输出:{2,3,4}
    for (int num:ans) cout<<num<<" ";
    return 0;
}

vector<int>answerQueries(vector<int>& nums,vector<int>& queries)
{
    sort(nums.begin(),nums.end()); // *排序*
    int m=nums.size(), n=queries.size();
    vector<int>f(m+1); // f[0]=0:空数组和是0; f[i]长度是i
    for (int i=0;i<m;i++)
        f[i+1]=f[i]+nums[i];
    vector<int>ans(n);
    for (int i=0;i<n;i++)
    {
        ans[i]=upper_bound(f.begin(),f.end(),queries[i])-f.begin()-1; // upper_bound(,,i)返回第1个>i的迭代器
    }
    return ans;
}