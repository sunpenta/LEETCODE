#include <bits/stdc++.h>
using namespace std;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int maxnum=0;
        for (int i=0; i<k; ++i)
        {
            maxnum=max(maxnum,nums[i]);
        }
        vector<int> res(n-k+1);
        for (int i=k; i<n; ++i)
        {
            if (nums[i]>=maxnum)
            {
                maxnum=nums[i]; 
            }
            else if (nums[i]<maxnum && nums[i-k]<maxnum)
            {}
            else
            {
                maxnum=*max_element(nums.begin()+i-k+1,nums.begin()+i);
            }
            res[i-k]=maxnum;
        }
        return res;
    }
    
int main()
{
    vector<int> nums =
    {1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int> res=maxSlidingWindow(nums, k);
    // ***
    // long long a = (static_cast<int64_t>(pow(2, 54)) - 1) % mod; // int64_t is long long
    // ***
    return 0;
}