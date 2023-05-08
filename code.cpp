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
        int res=0, i=0, j=0;
        while (i<=idx)
        {
            if (arrive[i]<leave[j])
            {               
                res=chairs.top();
                chairs.pop();
                ++i;
            }
            else if (arrive[i]<leave[j])
            {
                chairs.push(res);
                ++j;
            }
            else
            {
                ++i, ++j;
            }
        }
        return res;    
    }
    
int main()
{
    vector<vector<int>> times ={{33889,98676},{80071,89737},{44118,52565},{52992,84310},{78492,88209},{21695,67063},{84622,95452},{98048,98856},{98411,99433},{55333,56548},{65375,88566},{55011,62821},{48548,48656},{87396,94825},{55273,81868},{75629,91467}};
    int targetFriend =6;
    cout<<smallestChair(times,targetFriend)<<endl;
    // ***
    // long long a = (static_cast<int64_t>(pow(2, 54)) - 1) % mod; // int64_t is long long
    // ***
    return 0;
}