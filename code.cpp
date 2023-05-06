#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
    int fact(int a)
    {
        if (a==0 || a==1) return 1;
        return a*fact(a-1);
    }
    int C(int a, int b)
    {
        int res=fact(a)/fact(b)/fact(a-b);
        return res;
    }
    int all(int a)
    {
        int count=0;
        for (int i=1; i<=a; i++)
        {
            count=(count+C(a,i)%mod)%mod;
        }
        return count%mod;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size(), count=0;
        int  i=0,j;
        if (nums[0]>target) return 0;
        for (int j=n-1; j>=i; --j)
        {
            if (nums[i]+nums[j]<=target)
            {
                break;
            }
        }
        if (j-i>=1)
        count=all(j-i)%mod+1;        
        return count%mod;
    }
    
int main()
{
    cout<<fact(3)<<endl;
    vector<int> nums = {3,5,6,7}; int target = 9;
    cout<<numSubseq(nums,target)<<endl;
    return 0;
}