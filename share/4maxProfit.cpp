// 股票买卖-动态规划  l-188
// 买卖k次
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>&prices,int k);

int main()
{
    vector<int>prices={3,2,6,5,0,3}; int k=2; // 输入
    cout<<maxProfit(prices,k)<<endl; // 输出:7 [2,6] [0,3]
    system("pause");
}

int maxProfit(vector<int>&prices,int k)
{
    vector<int>buy(k+1,-prices[0]), sell(k+1,0);
    for (int i=1;i<prices.size();i++)
    {
        for (int j=1;j<=k;j++)
        {
            buy[j]=max(buy[j],sell[j-1]-prices[i]); // 第j次买完成，买i
            sell[j]=max(sell[j],buy[j]+prices[i]); // 第j次卖完成,卖i
        }
    }
    return sell[k];
}