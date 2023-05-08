#include <bits/stdc++.h>
using namespace std;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size(), m=tasks.size();
        vector<tuple<int,int,int>> times; // <time,type,index==start time>,1:start 0:end
        for (int i=0; i<m; ++i)
        {
            times.push_back({i,1,i});
            times.push_back({i+tasks[i],0,i});
        }
        sort(times.begin(),times.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; // servers
        for (int i=0; i<n; ++i)
        {
            pq.push({servers[i],i});
        }
        vector<int> ans(m);
        for (auto& [time,type,idx]:times)
        {
            if (type==1)
            {
                ans[idx]=pq.top().second;
                pq.pop();
            }
            else
            {
                pq.push({servers[ans[idx]],ans[idx]});
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