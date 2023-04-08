//从起点能否跳到终点- dfs l-1306
// 起点：start；终点：元素为0的下标；方向：向左或向右 数组每个元素代表跳跃最大长度；一定能到达终点
#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int>&nums,int start);

int main()
{
    vector<int>nums={4,2,3,0,3,1,2};int start=5; // 输入
    cout<<boolalpha<<canJump(nums,start)<<endl; // 输出
    system("pause");
}

bool canJump(vector<int>&nums,int start)
{
    if (start<0 || start>=nums.size() || nums[start]<0)
        return false;
    if (nums[start]==0)
        return true;
    nums[start]*=-1;//变成负数，防重复
    return canJump(nums,start-nums[start]) || canJump(nums,start+nums[start]);
}

/*
bool dfs(vector<int>&nums,int start,vector<bool>&visit)
{
    if (start<0 || start>=nums.size()) return false;
    if (nums[start]==0) return true;
    visit[start]=true;//标记start
    return dfs(nums,start-nums[start],visit)||dfs(nums,start+nums[start],visit);    
}

bool canJump(vector<int>&nums,int start)
{
    vector<bool>visit{false};//初始化false
    return dfs(nums,start,visit);
}*/