#include <bits/stdc++.h>
using namespace std;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size(), m=tasks.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > times; // <end,server>
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > server; // servers
        for (int i=0; i<n; ++i)
        {
            server.push({servers[i],i});
        }
        vector<int> ans(m);
        for (int i=0; i<m; ++i)
        {
            int start=i, end=start+tasks[i]; 
            while (!times.empty() && times.top().first<=start)
            {
                int s=times.top().second;
                server.push({servers[s],s});
                times.pop();
            }
            
            if (server.empty())
            {
                start=times.top().first, end=start+tasks[i];
            }
            else
            {
                ans[i]=server.top().second;
                server.pop();
                times.push({end,ans[i]});
            }
        }
        return ans;
    }
    
int main()
{
    vector<int> servers =
    {10,63,95,16,85,57,83,95,6,29,71};
    vector<int> tasks =
    {70,31,83,15,32,67,98,65,56,48,38,90,5};
    vector<int> ans=assignTasks(servers, tasks);
    // ***
    // long long a = (static_cast<int64_t>(pow(2, 54)) - 1) % mod; // int64_t is long long
    // ***
    return 0;
}