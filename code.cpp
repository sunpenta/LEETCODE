#include <bits/stdc++.h>
using namespace std;
    int removeElement(vector<int>& nums, int val) {
        int repeat=0, n=nums.size(), i=0, j=n-1;
        while (i<j)
        {
            if (nums[i]==val)
            {
                while (nums[j]==val)
                    --j;
                swap(nums[i],nums[j--]);
            }
            ++i;
        }
        return i;
    }
    
int main()
{
    vector<int>nums ={0,1,2,2,3,0,4,2}; int val=2;
    removeElement(nums,val);
    string s ="abcz"; int k=26;
    // cout<<smallestBeautifulString(s,k);
    int n = 2; vector<vector<int>> meetings = {{0,10},{1,2},{12,14},{13,15}};
    // int res=mostBooked(n, meetings); // {{0,10},{1,5},{2,7},{3,4}}  n=2
     // (72/82)runtime error: signed integer overflow: 2147400001 + 300000 cannot be represented in type 'int'
   // vector<int> res=maxSlidingWindow(nums, k);
    // ***
    // long long a = (static_cast<int64_t>(pow(2, 54)) - 1) % mod; // int64_t is long long
    // ***
    // -7,-8,7,5,7,1,6,0
    return 0;
    /*n =
10*/
}