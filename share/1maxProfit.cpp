// 股票买卖-贪心/动态规划  l-121
// 买卖一次
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>&prices);

int main()
{
    vector<int>prices={7,1,5,3,6,4}; // 输入
    cout<<maxProfit(prices)<<endl; // 输出:5 1,6
    system("pause");
}

int maxProfit(vector<int>&prices)
{
    int maxprofit=0, minprice=prices[0];
    for (int i=1;i<prices.size();i++)
    {
        minprice=min(minprice,prices[i]); // 买入最低价格
        maxprofit=max(maxprofit,prices[i]-minprice);
    }
    return maxprofit;
}