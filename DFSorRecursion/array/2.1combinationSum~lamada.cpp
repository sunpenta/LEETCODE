// 组合之和 - 回溯+lamada表达式  l-39
// 元素可重复使用；组合无重复
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>combinationSum(vector<int>& candidates, int target);

int main()
{
    vector<int>candidates{2,3,6,7}; int target=7; // 输入
    vector<vector<int>>ans=combinationSum(candidates,target); // 输出:
    for (int i=0; i<ans.size(); i++) // {{2,2,3},{7}}
    {
        for(auto num:ans[i])
            cout<<num<<" ";
        cout<<endl;
    }
    return 0;
}

vector<vector<int>>combinationSum(vector<int>& candidates, int target)
{  
    int n=candidates.size();
    vector<vector<int>>ans; vector<int>combine;
    int sum=0; // 子数组和
    // sum=target; lamada表达式:[&]：捕获所有引用，函数参数:int back; function<返回类型(参数类型)> 函数名
    function<void(int)> dfs=[&] (int back)
    {
        if (sum>target) // 不满足条件，返回
            return;
        else if (sum==target) // 满足条件
            ans.emplace_back(begin(combine),end(combine));          
        else
        {
            for (int i=back; i<n; i++)
            {
                sum+=candidates[i];
                combine.emplace_back(candidates[i]);
                dfs(i); // 从i开始搜索
                sum-=candidates[i];
                combine.pop_back();
            }
        }
    };
    dfs(0);
    return ans;
}