// 机器人最小遍历距离 - dp  l-2463
// robot.length, factory.length⋿[1,100], robot, position⋿[-1e9,1e9]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long minTotalDiatance(vector<int>& robot, vector<vector<int>>& factory);

int main()
{
    vector<int> robot={0,4,6}; vector<vector<int>> factory={{2,2},{6,2}}; // input
    cout<<minTotalDiatance(robot,factory)<<endl; // output:4 |0-2|+|4-2|+|6-6|=4
    return 0;
}

long long minTotalDiatance(vector<int>& robot, vector<vector<int>>& factory)
{
    int n=robot.size(), m=factory.size();
    sort(robot.begin(),robot.end());
    sort(factory.begin(),factory.end());
    vector<long long> dp(n+1,1e15); // dp[i]:repair i robot min总距离; note:<long long>
    dp[0]=0; // 0 robot travel 0
    for (int i=0; i<m; ++i)
    {
        for (int k=0; k<factory[i][1]; ++k)
        {
            for (int j=n-1; j>=0; --j)
            {
                dp[j+1]=min(dp[j+1],dp[j]+abs(factory[i][0]-robot[j]));
            }
        }
    }
    return dp[n];
}