#include <bits/stdc++.h>
using namespace std;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<int> in, out;
        for (auto time:times)
        {
            in.emplace_back(time[0]);
            out.emplace_back(time[1]);
        }
        sort(in.begin(),in.end());
        sort(out.begin(),out.end());
        int idx=find(in.begin(),in.end(),times[targetFriend][0])-in.begin();
        cout<<idx;
        int i=0, j=0, res=0;
        while (idx--)
        {
            if (in[i]<out[j])
            {
                res++;
                ++i;
            }
            else
            {
                --res;
                ++j;
            }
        }
        return res;    
    }
    
int main()
{
    vector<vector<int>> times =
{{33889,98676},{80071,89737},{44118,52565},{52992,84310},{78492,88209},{21695,67063},{84622,95452},{98048,98856},{98411,99433},{55333,56548},{65375,88566},{55011,62821},{48548,48656},{87396,94825},{55273,81868},{75629,91467}};
    int targetFriend =6;
    cout<<smallestChair(times,targetFriend)<<endl;
    // ***
    // long long a = (static_cast<int64_t>(pow(2, 54)) - 1) % mod; // int64_t is long long
    // ***
    return 0;
}