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
    vector<vector<int>> times ={{18,19},{10,11},{21,22},{5,6},{2,3},{6,7},{43,44},{48,49},{53,54},{12,13},{20,21},{34,35},{17,18},{1,2},{35,36},{16,17},{9,10},{14,15},{25,26},{37,38},{30,31},{50,51},{22,23},{3,4},{27,28},{29,30},{33,34},{39,40},{49,50},{15,16},{4,5},{46,47},{51,52},{32,33},{11,12},{28,29},{47,48},{36,37},{40,41},{42,43},{52,53},{41,42},{31,32},{23,24},{8,9},{19,20},{24,25},{26,27},{45,46},{44,45},{7,8},{13,14},{38,39}};
    int targetFriend =8;
    cout<<smallestChair(times,targetFriend)<<endl;
    // ***
    // long long a = (static_cast<int64_t>(pow(2, 54)) - 1) % mod; // int64_t is long long
    // ***
    return 0;
}