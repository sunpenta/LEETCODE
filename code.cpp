#include <bits/stdc++.h>
using namespace std;
    int smallestChair(vector<vector<int>>& _times, int targetFriend) {
        priority_queue<int, vector<int>, greater<int> > chairs; // reserved chairs
        int n=_times.size();
        for (int i=0; i<n; ++i)
        {
            chairs.push(i);
        }
        vector<pair<int,int>> arrive; // <time,friend> 
        vector<pair<int,int>> leave;  // <time,friend>
        for (int i=0; i<n; ++i)
        {
            arrive.push_back({_times[i][0],i});
            leave.push_back({_times[i][1],i});
        }
        sort(arrive.begin(),arrive.end());
        sort(leave.begin(),leave.end());
        pair<int,int> target={_times[targetFriend][0],targetFriend};
        int idx=find(arrive.begin(),arrive.end(),target)-arrive.begin();
        int i=0, j=0;
        vector<int> seat(n);
        while (i<=idx)
        {
            if (arrive[i].first<leave[j].first)
            {               
                seat[arrive[i].second]=chairs.top();
                chairs.pop();
                ++i;
            }
            else if (arrive[i].first>leave[j].first)
            {
                chairs.push(seat[leave[j].second]); // j leave
                ++j;
            }
            else
            {
                seat[i]=seat[leave[j].second];
                ++i, ++j;
            }
        }
        return seat[targetFriend];    
    }
    
int main()
{
    vector<vector<int>> times ={{1,5},{2,3},{3,9},{4,7},{5,8}}; int targetFriend =3;
    cout<<smallestChair(times,targetFriend)<<endl;
    // ***
    // long long a = (static_cast<int64_t>(pow(2, 54)) - 1) % mod; // int64_t is long long
    // ***
    return 0;
}