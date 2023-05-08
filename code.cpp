#include <bits/stdc++.h>
using namespace std;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int> pq; // less<>
        for (int i=0; i<k; ++i)
            pq.push(nums[i]);
        vector<int> res(n-k+1);
        res[0]=pq.top();
        for (int i=k; i<n; ++i)
        {
            while (!pq.empty() && (nums[i]>pq.top() || pq.top()==nums[i-k]))
            {
                pq.pop();
            }
            pq.push(nums[i]);
            res[i-k+1]=pq.top();
        }
        return res;
    }
    
int main()
{
    vector<int> nums =
    {1,3,1,2,0,5};
    int k=3;
    vector<int> res=maxSlidingWindow(nums, k);
    // ***
    // long long a = (static_cast<int64_t>(pow(2, 54)) - 1) % mod; // int64_t is long long
    // ***
    return 0;
}