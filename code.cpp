#include <bits/stdc++.h>
using namespace std;
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int m=queries.size(), count=0;
        vector<int> res(m), nums(n,0);
        for (int i=0; i<m; ++i)
        {
            int j=queries[i][0];
            int pre=nums[j];
            cout<< pre<<" ";
            nums[j]=queries[i][1];
            if ((j<n-1 && nums[j]==nums[j+1] || j>0 && nums[j]==nums[j-1]) && nums[j]!=pre)
            {
                ++count;
                res[i]=count;
            }
            else if (pre!=0 && nums[j]!=pre && (j<n-1 && pre==nums[j+1] || j>0 && pre==nums[j-1]))
            {
                count=max(0,--count);
                res[i]=count;
            }
            else                   
                res[i]=count;   
        }
        return res;
    }
    
int main()
{
    // ***
    long long a = (static_cast<int64_t>(pow(2, 54)) - 1) % mod; // int64_t is long long
    // ***
    long long b=(long long) (pow(2,54))%mod;
    cout<<a<<" "<<b<<endl;
    vector<int> nums = {6,10,12,3,29,21,12,25,17,19,16,1,2,24,9,17,25,22,12,22,26,24,24,11,3,7,24,5,15,30,23,5,20,10,19,20,9,27,11,4,23,4,4,12,22,27,16,11,26,10,23,26,16,21,24,21,17,13,21,9,16,17,27}; 
    int target = 26;
    //cout<<numSubseq(nums,target)<<endl;
    return 0;
}