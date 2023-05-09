#include <bits/stdc++.h>
using namespace std;
    int mostBooked(int n, vector<vector<int>>& meetings) {
       vector<int> room(n); // room[i] have meetting number
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > meeting;
        priority_queue<int,vector<int>,greater<int>> free;
        for (int i=0; i<n; ++i)
            free.push(i);
        sort(meetings.begin(),meetings.end());
        int start=0, interval;
        for (int i=0; i<meetings.size(); ++i)
        {
            start=max(start,meetings[i][0]); // change
            interval=meetings[i][1]-meetings[i][0];
            if (free.empty() && start<meeting.top().first)
            {
                start=meeting.top().first; // delay
            }
            while (!meeting.empty() && start>=meeting.top().first)
            {
                int idx=meeting.top().second;
                free.push(idx);
                meeting.pop();
            }
            int k=free.top();
            free.pop();
            room[k]++;
            meeting.push({start+interval,k});
        }
        int res=0;
        for (int i=0; i<n; ++i)
        {
            res=max(res,room[i]);
        }
        return res;
    }
    
int main()
{
    int n = 2; vector<vector<int>> meetings = {{0,10},{1,2},{12,14},{13,15}};
    int res=mostBooked(n, meetings); // {{0,10},{1,5},{2,7},{3,4}}  n=2
    cout<<res;
   // vector<int> res=maxSlidingWindow(nums, k);
    // ***
    // long long a = (static_cast<int64_t>(pow(2, 54)) - 1) % mod; // int64_t is long long
    // ***
    // -7,-8,7,5,7,1,6,0
    return 0;
}