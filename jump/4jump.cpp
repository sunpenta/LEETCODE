//跳跃最少次数-bfs+队列   l-45
// 起点：0；终点：n-1；方向：i+1 、i-1 或者j 满足nums[i] == nums[j]且i!=j;元素有正负
#include <bits/stdc++.h>
using namespace std;
int jump(vector<int>&nums);

int main()
{
    vector<int>nums={100,-23,-23,404,100,23,23,23,3,404};//输入
    cout<<jump(nums)<<endl;
    system("pause");
}

int jump(vector<int>&nums)
{
    int n=nums.size();
    unordered_map<int,vector<int>>mp;//存放相等元素的下标
    //逆序输出，先读后面的下标，那么步数少
    for (int i=n-1;i>=0;i--)
        mp[nums[i]].emplace_back(i);

    vector<int>dist(n,INT_MAX); //存到下标i的最小步数，设一个不可能的数，下面用
    dist[0]=0; //在0走了0步
    queue<int>qe; //队列：经过的下标
    qe.push(0);//0是起点
    
    while (!qe.empty())
    {   // 更新index,step
        int index=qe.front(); //下标
        int step=dist[index]; // 步数
        qe.pop();

        if (index==n-1) return step;
        //第一种情况: 向左i-1
        if (index-1>=0 && dist[index-1]==INT_MAX)
        {
            qe.push(index-1);
            dist[index-1]=step+1;
        }
        //第二种情况：向右i+1
        if (index+1<n && dist[index+1]==INT_MAX)
        {
            qe.push(index+1);
            dist[index+1]=step+1;
        }
        //第三种情况：相等元素的下标nums[j]=nums[i]
        const auto & indexes=mp[nums[index]]; //写法
        for (auto x:indexes)
        {
            if (dist[x]==INT_MAX)
            {
                qe.push(x);
                dist[x]=step+1;
            }
        }
        mp[nums[index]].clear();//防止无限循环
    }
    return -1;//没有到终点
}