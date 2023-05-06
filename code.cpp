#include <bits/stdc++.h>
using namespace std;
    int mod=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());  
        int n=nums.size(), count=0;
        if (nums[0]>target) return 0;
        int j=n-1;
        for (int i=0; i<n; ++i)
        {
            if (nums[i]+nums[i]<=target)
                ++count;
            
            while (nums[i]+nums[j]>target)
            {
                --j;
            }
            count+=(pow(2,j-i)-1);
        }        
        return count%mod;
    }
    
int main()
{
    vector<int> nums = {3,5,6,7}; int target = 9;
    cout<<numSubseq(nums,target)<<endl;
    return 0;
}