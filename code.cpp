#include <bits/stdc++.h>
using namespace std;
    int num=0, mod=1e9+7;
    void dfs(vector<int>& nums, int target, int index)
    {
        if (target>=0)
        {
            ++num;
            num%=mod;
            // return;
        }
        for (int i=index; i<nums.size(); ++i)
        {
            if (target<nums[i]) break;
            if (i>index && nums[i]==nums[i-1]) continue;
            dfs(nums,target-nums[i],i+1);
        }
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        dfs(nums,target,0);
        return num;
    }
    
int main()
{
    vector<int> nums = {3,5,6,7}; int target = 9;
    cout<<numSubseq(nums,target)<<endl;
    return 0;
}