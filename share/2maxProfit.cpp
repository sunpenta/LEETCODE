// 股票买卖-贪心 l-122
// 多次买卖；最多持有一支股票；可在同一天买卖
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>&prices);

int main()
{
    vector<int>prices={7,1,5,3,6,4}; // 输入
    cout<<maxProfit(prices)<<endl; // 输出
    system("pause");
}

int maxProfit(vector<int>&prices)
{
    int profit=0; // *初始值必须设0*
    for (int i=1;i<prices.size();i++)
    {
        profit+=max(0,prices[i]-prices[i-1]); // 只要利润为正即买
    }
    return profit;
}