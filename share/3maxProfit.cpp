// 股票买卖-动态规划  l-123
// 只可买卖两次
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>&prices);

int main()
{
    vector<int>prices={7,1,5,3,6,4}; // 输入
    cout<<maxProfit(prices)<<endl; // 输出:7 [1,5],[3,6]
    system("pause");
}

int maxProfit(vector<int>&prices)
{
    int buy1=-prices[0], sell1=0; // 第一次买，第一次卖
    int buy2=-prices[0], sell2=0; // 第二次买，第二次卖
    for (int i=1;i<prices.size();i++)
    {
        buy1=max(buy1,-prices[i]); // 第1次买完,买i
        sell1=max(sell1,buy1+prices[i]); // 第1次卖了,卖i
        buy2=max(buy2,sell1-prices[i]); // 第2次买了，买i
        sell2=max(sell2,buy2+prices[i]); // 第二次卖了，卖i
    }
    return sell2;
}