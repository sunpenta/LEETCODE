// 子数组大小为k的组合-回溯  l-78+90
// 输入数组元素有重复；不可重复使用元素；无重复子集组合
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>subsetsWithDup(vector<int>&nums,int k);

int main()
{
    vector<int>nums={1,2,2}; int k=2; // 输入
    vector<vector<int>>subsets=subsetsWithDup(nums,k); // 输出
    for (int i=0;i<subsets.size();i++)  // {{1,2},{2,2}}
    {
        for (auto num:subsets[i])
            cout<<num<<" ";
        cout<<endl;
    }
    system("pause");
}

void dfs(vector<vector<int>>&subsets,vector<int>subset,vector<int>&nums,int k,int index)
{
    if (subset.size()==k) // 终止条件
    {
        subsets.emplace_back(subset);
        return;
    }
    if (index==nums.size()) return;

    for (int i=index;i<nums.size();i++)
    {
        if (i>index && nums[i]==nums[i-1]) continue; // 去重
        subset.emplace_back(nums[i]);
        dfs(subsets,subset,nums,k,i+1);
        subset.pop_back();
    }
}

vector<vector<int>>subsetsWithDup(vector<int>&nums,int k)
{
    vector<vector<int>>subsets; vector<int>subset;
    dfs(subsets,subset,nums,k,0);
    return subsets;
}
