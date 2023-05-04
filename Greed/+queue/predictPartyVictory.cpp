// 预测政党胜利 - greedy+queue  l-649
// 时间复杂度:O(n), 空间复杂度:O(n)
#include <iostream>
#include <queue>
using namespace std;
string predicrPartyVictory(string senate);

int main()
{
    string senate="DDRRRR"; // input
    cout<<predicrPartyVictory(senate)<<endl; // output:Radiant
    return 0;
}
string predicrPartyVictory(string senate)
{
    int n=senate.length();
    queue<int> q1, q2;
    for (int i=0; i<n; ++i)
    {
        if (senate[i]=='R')
            q1.push(i);
        else
            q2.push(i);
    }

    while (!q1.empty() && !q2.empty())
    {
        int r_index=q1.front(), d_index=q2.front();
        q1.pop(); q2.pop();
        if (r_index<d_index)
        {
            q1.push(r_index+n);
        }
        else
        {
            q2.push(d_index+n);
        }
    }
    return q2.empty()?"Radiant":"Dire";
}