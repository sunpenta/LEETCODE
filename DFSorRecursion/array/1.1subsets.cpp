// 所有子集 - 回溯 l-78
// 无重复组合
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>subsets(vector<int>&nums);

int main()
{
    vector<int>nums={1,2,3}; // 输入
    vector<vector<int>>allsubsets=subsets(nums); // 输出:
    for (int i=0;i<allsubsets.size();i++) // {{},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}}
    {
        for (auto num:allsubsets[i])
            cout<<num<<" ";
        cout<<endl;
    }
    return 0;
}

void dfs(vector<vector<int>>&allsubsets,vector<int>&subset,vector<int>&nums,int index)
{
    if (index==nums.size())
    {
        allsubsets.emplace_back(subset);
        return;
    }

    subset.emplace_back(nums[index]);
    dfs(allsubsets,subset,nums,index+1);
    subset.pop_back();
    dfs(allsubsets,subset,nums,index+1); 
}

vector<vector<int>>subsets(vector<int>&nums)
{
    vector<vector<int>>allsubsets; vector<int>subset;
    dfs(allsubsets,subset,nums,0);
    return allsubsets;
}
