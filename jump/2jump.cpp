//跳跃最少次数-贪心   l-45
// 起点：0；终点：n-1；方向：向右 数组每个元素代表跳跃最大长度；一定能到达终点
#include <bits/stdc++.h>
using namespace std;
int jump(vector<int>&nums);

int main()
{
    vector<int>nums={2,3,0,1,4};//输入
    cout<<jump(nums)<<endl;//输出
    system("pause");
}

//只需要找到倒数第二个位置就可以了,因为如果最远距离到第二个位置那只要步数+1就一定可以到最后一步
// 每次在上次能跳到的范围（end）内选择一个能跳的最远的位置（也就是能跳到max_far位置的点）作为下次的起跳点
int jump(vector<int>&nums)
{   //maxfar:最远范围;end:上次最远，下次起跳；count:跳跃次数
    int maxfar=0,end=0,count=0;
    for (int i=0;i<nums.size()-1;i++)
    {
        maxfar=(maxfar,i+nums[i]); //更新最远
        if (i==end)
        {   
            end=maxfar; //下次起跳
            count++;
        }
    }
    return count;
}
