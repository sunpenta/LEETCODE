// 组合之和 - 回溯  l-39
// 元素可重复使用；组合无重复
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>combinationSum(vector<int>& candidates, int target);

int main()
{
    vector<int>candidates{2,3,6,7}; int target=7; // 输入
    vector<vector<int>>ans=combinationSum(candidates,target); // 输出:
    for (int i=0;i<ans.size();i++) // {{2,2,3},{7}}
    {
        for (auto num:ans[i])
            cout<<num<<" ";
        cout<<endl;
    }
    return 0;
}

// combine:target-子数组和=0; ans:所有子数组; index:搜索起点candidates[index]
void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int n, int index)
{
    if (target==0) // 终止条件
    { 
        ans.emplace_back(combine);
        return;
    }
    for (int i=index;i<n;i++) // 循环
    {
        if (target<candidates[i]) // 剪枝
            break;
        combine.emplace_back(candidates[i]);                  // dfs(...,i)保证可重复使用元素
        dfs(candidates,target-candidates[i],ans,combine,n,i); // 目标值变为：target-candidates[i]
        combine.pop_back();
    }
}
// 子数组和=target
vector<vector<int>>combinationSum(vector<int>&candidates,int target)
{
    vector<vector<int>>ans; vector<int>combine; // 组合集；子数组
    int n=candidates.size();
    sort(candidates.begin(),candidates.end()); // 排序
    dfs(candidates,target,ans,combine,n,0);

    return ans;  
}