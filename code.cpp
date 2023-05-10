#include <bits/stdc++.h>
using namespace std;
    /*int removeElement(vector<int>& nums, int val) {
        int repeat=0, n=nums.size(), i=0, j=n-1;
        while (i<=j)
        {
            if (nums[i]==val)
            {
                while (i<=j && nums[j]==val)
                    --j;
                if (i<j) // in case n==1
                swap(nums[i],nums[j--]);
            }
            ++i;
        }
        return i;
    }*/
    int totalFruit(vector<int>& fruits) {
        int res=0, cur=0;
        cur=1;
        unordered_map<int,int> mp;
        mp[fruits[0]]++;
        for (int i=1; i<fruits.size(); ++i)
        {
            
            
            cur++;
            mp[fruits[i]]++;
            if (i>1 && (mp.size()==2 || !mp.count(fruits[i])))
            {
                cur-=mp[fruits[i-2]];
                cur++;
                mp.erase(mp.find(fruits[i-2]));
            }
            res=max(res,cur);
        }
        return res;
    }
int main()
{

    vector<int> nums = {1,0,3,4,3}; int target=7;
    totalFruit(nums);
    //minSubArrayLen(target, nums);
    //string s ="xywrrmp", t="xywrrmu#p";
    //backspaceCompare(s,t);
    //vector<int>nums ={1}; int val=1;
    // removeElement(nums,val);
    // string s ="abcz"; int k=26;
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