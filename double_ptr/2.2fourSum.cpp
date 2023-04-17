// 四数之和-双指针  l-18
// -1e9<=nums[i]<=1e9; -1e9<=target<=1e9
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>fourSum(vector<int>&nums,int traget);

int main()
{
    vector<int> nums = {1,0,-1,0,-2,2};int target = 0; // 输入
    vector<vector<int>>ans=fourSum(nums,target); // 输出:{{1,0,-1,0},{0,0,-2,2},{1,-1,-2,2}}
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 4; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }  
    return 0;
}

// 四数之和等于目标值
vector<vector<int>>fourSum(vector<int>&nums,int target)
{
    vector<vector<int> > ans; // 四数组合
    int n=nums.size();
    // 特殊情况:元素个数<4
    if (n<4) return ans; 

    sort(nums.begin(),nums.end()); // 从小到大排序
    // 四数下标分别是i,j,k,h
    for (int i=0;i<n-3;i++)
    {   
        if (nums[i]==nums[i+1]) continue; // 跳过相等元素
        // 判断节省运算; long防止溢出
        long min=(long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3];
        if (min>target) break; // 最小值大于目标值，找不到四元组
        long max=(long)nums[i]+nums[n-3]+nums[n-2]+nums[n-1];
        if (max<target) break; // 最大值小于目标值，找不到四元组

        for (int j=i+1;j<n-2;j++)
        {
            if (j>i+1 && nums[j]==nums[j-1]) continue; // 判断条件很重要，改变结果

            long min1=(long)nums[i]+nums[j]+nums[j+1]+nums[j+2];
            if (min1>target) break;
            long max1=(long)nums[i]+nums[j]+nums[n-2]+nums[n-1];
            if (max1<target) continue;

            // 双指针
            int k=j+1, h=n-1;
            while (k<h)
            {
                int cur=nums[i]+nums[j]+nums[k]+nums[h];
                if (cur==target)
                {
                    ans.emplace_back(vector<int>{nums[i],nums[j],nums[k],nums[h]});
                    k++; // 找所有四元组
                    while (k<h && nums[k]==nums[k+1])
                        k++;
                    h--;
                    while (k<h && nums[h]==nums[h-1]) 
                        h--;
                }
                else if (cur<target) 
                    k++;
                else 
                    h--;
            }
        }
    }
    return ans;
}