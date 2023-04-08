// 从起点能否跳到终点-贪心 l-55
// 起点：0；终点：n-1；方向：向右 数组每个元素代表跳跃最大长度
#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int>&nums);

int main()
{
    vector<int>nums={3,2,1,0,4}; // 输入
    cout<<boolalpha<<canJump(nums)<<endl; // 输出
    system("pause");
}

bool canJump(vector<int>&nums)
{
    int n=nums.size();
    int maxfar=0; // 最远长度
    // 只能在maxfar范围活动
    for (int i=0;i<=maxfar;i++) // 把i<n 改成 i<=maxfar 
    {
        maxfar=max(maxfar,i+nums[i]); // 更新最远
        if (maxfar>=n-1)
            return true;
    }
    return false;
}
