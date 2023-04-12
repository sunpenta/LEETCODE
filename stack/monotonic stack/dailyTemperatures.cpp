// 每日温度 - monotonic stack   l-739
// 等？天有更高温度; 时间复杂度:O(n) 空间复杂度:O(1)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures);

int main()
{
    vector<int> temperatures={73,74,75,71,69,72,76,73}; // input
    vector<int> res=dailyTemperatures(temperatures); // output: {1,1,4,2,1,1,0,0}
    for (int i:res) cout<<i<<" ";
}

vector<int> dailyTemperatures(vector<int>& temperatures)
{
    int n=temperatures.size();
    stack<int> sk; // higher temp's index
    vector<int> res(n);
    for (int i=0; i<n; i++)
    {
        while (!sk.empty() && temperatures[i]>temperatures[sk.top()])
        {
            int tmp=sk.top(); sk.pop();
            res[tmp]=i-tmp;
        }
        sk.push(i);
    }
    return res;
}