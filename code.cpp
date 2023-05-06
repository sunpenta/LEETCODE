#include <bits/stdc++.h>
using namespace std;
    int mod=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());  
        int n=nums.size();long long count=0;
        if (nums[0]>target) return 0;

        for (int i=0,j=n-1; i<n; ++i)
        {
            if (nums[i]+nums[i]<=target)
                ++count;
            else
                break;
            while (nums[i]+nums[j]>target)
            {
                --j;
            }
            if (j>i)
            {
                int cur=(long long) (pow(2,j-i)-1) % mod;
                count+=cur;
            }
        }        
        return count%mod;
    }
    
int main()
{
    int cur=(long long) (pow(2,54)-1) % mod;
    cout<<cur<<endl;
    vector<int> nums = {6,10,12,3,29,21,12,25,17,19,16,1,2,24,9,17,25,22,12,22,26,24,24,11,3,7,24,5,15,30,23,5,20,10,19,20,9,27,11,4,23,4,4,12,22,27,16,11,26,10,23,26,16,21,24,21,17,13,21,9,16,17,27}; 
    int target = 26;
    //cout<<numSubseq(nums,target)<<endl;
    return 0;
}