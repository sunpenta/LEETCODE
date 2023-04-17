// 组合之和-回溯  l-40
// 输入数组有重复元素；元素不可重复使用; 组合无重复
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>combinationSum2(vector<int>&candidates,int target);//声明子函数

int main()
{
    vector<int>candidates{10,1,2,7,6,1,5}; int target=8; // 输入元素有重复
    vector<vector<int>>ans=combinationSum2(candidates,target); // 输出:
    for (int i=0;i<ans.size();i++) // {{1,1,6},{1,2,5},{1,7},{2,6}}
    {
        for (auto num:ans[i])
            cout<<num<<" ";
        cout<<endl;
    }
    return 0;
}

// 从candidates[index]开始搜索，找子数组(combine)和=target，ans:所有组合
void dfs(vector<int>&candidates,vector<vector<int>>&ans,vector<int>&combine,int n,int target,int index)
{
    if (target==0)
    {
        ans.emplace_back(combine);
        return;
    }  
    for (int i=index;i<n;i++)
    {
        if (target<candidates[i]) break; 
        if (i>index && candidates[i]==candidates[i-1]) continue; // *横向去重*
        combine.emplace_back(candidates[i]);
        dfs(candidates,ans,combine,n,target-candidates[i],i+1); // dfs(...,i+1):combine里无重复,纵向
        combine.pop_back();
    }
}
// 数组和=target
vector<vector<int>>combinationSum2(vector<int>&candidates,int target)
{
    int n=candidates.size();
    vector<vector<int>>ans; vector<int>combine;
    sort(candidates.begin(),candidates.end()); // 必须排序 {1,1,2,5,6,7,10} 8
    dfs(candidates,ans,combine,n,target,0);
    return ans;
}