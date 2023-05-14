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
        int n=fruits.size();
        unordered_map<int,int> mp;
        int i=0, j=0; // [i,j]
        for (; j<n; ++j)
        {
            mp[fruits[j]]++;
            if (mp.size()>2)
            {
                --mp[fruits[i]];       
                if (mp[fruits[i]]==0)
                {
                    mp.erase(fruits[i]);
                }
                i++;
            }
        }
        return j-i;
    }
        string minWindow(string s, string t) {
        int m=s.length(), n=t.length();
        if (m==0 || n==0) return "";
        unordered_map<char,int> mpt; // <t's ch, number>
        for (char ch:t)
        {
            mpt[ch]++;
        }
        int i=0, j=0, minlen=1e5+1, begin=0, needlen=n;
        while (j<=m && i<m)
        {
            if (needlen) 
            {
                if (j==m) break;
                --mpt[s[j]];
                if (mpt[s[j]]>=0)
                    --needlen;
                ++j;         
            }
            else
            {   
                if (j-i<minlen) // [i,j)
                {
                    minlen=min(minlen,j-i);
                    begin=i;
                }  
                mpt[s[i]]++;
                if (mpt[s[i]]>0)
                    ++needlen;
                ++i;                 
            }         
        }
        return minlen==1e5+1?"":s.substr(begin,minlen);  
    }
        int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        vector<vector<int>> dp(m,vector<int>(n));
        for (int i=0; i<n; ++i)
        {
            if (i>0) 
                dp[0][i]=dp[0][i-1]; // firstly          
            if (nums2[i]==nums1[0])
                dp[0][i]=1;
        }
         for (int i=0; i<m; ++i)
        {
            if (i>0) 
                dp[i][0]=dp[i-1][0];
            if (nums1[i]==nums2[0])
                dp[i][0]=1;
        }       
        for (int i=1; i<m; ++i)
        {
            for (int j=1; j<n; ++j)
            {
                if (nums1[i]==nums2[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                
            }
        }
        return dp[m-1][n-1];
    }
    int get(map<int,int>& mp, int x)
    {
        int res=0, count=0;
        auto it=mp.begin();
        while (count<x)
        {
            count+=it->second;
            res=it->first;
            ++it;
        }
        return res;
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> res(n-k+1);
        map<int,int> mp;
        for (int i=0; i<k; ++i)
        {
            mp[nums[i]]++;
        }
        res[0]=min(0,get(mp,x));
        for (int i=k; i<n; ++i)
        {
            if (--mp[nums[i-k]]==0)
                mp.erase(nums[i-k]);
            ++mp[nums[i]];
            res[i-k+1]=min(0,get(mp,x));
        }
        return res;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n);
        dp[0]=questions[0][0];
        int id=questions[0][1]+1;
        if (id<n)
            dp[id]=dp[0]+questions[id][0];
        for (int i=1; i<n; ++i)
        {
            dp[i]=max(dp[i], (long long)questions[i][0]);
            dp[i]=max(dp[i-1], dp[i]);
            id=i+questions[i][1]+1; // next
            if (id<n)
                dp[id]=max(dp[id],dp[i]+questions[id][0]);
        }
        return dp[n-1];
    }
    int gcd(int x,int y)
    {
        int res=1;
        for (int i=2; i<=x; ++i)
        {
            if (x%i==0 && y%i==0)
            {
                res=i;
            }
        }
        return res;
    }
    int get(vector<int> nums, int x)
{
    int res=1, gd=1;
    for (int num:nums)
    {
        if (num!=x && gcd(num,x)>gd)
        {
            gd=gcd(num,x);
            res=num;
        }
    }
    return res;
}
int main()
{
        vector<int> nums={1,2,3,4,5,6};
        
        sort(nums.begin(),nums.end());
        int score=0, turn=nums.size()/2;
        int i=nums.size()-1;
        while (!nums.empty())
        {
            i=nums.size()-1;
            for (int j=nums.size()-2; j>=0; j--)
            {
                int y=nums[i], x=get(nums,y);
                int gd=gcd(x,y);               
                {
                    score+=turn*gd;
                    nums.erase(find(nums.begin(),nums.end(),x));
                    nums.erase(find(nums.begin(),nums.end(),y));
                    turn--;
                    break;
                }               
            }
        }
        return 0;   
    }
    // vector<vector<int>> questions={{21,2},{1,2},{12,5},{7,2},{35,3},{32,2},{80,2},{91,5},{92,3},{27,3},{19,1},{37,3},{85,2},{33,4},{25,1},{91,4},{44,3},{93,3},{65,4},{82,3},{85,5},{81,3},{29,2},{25,1},{74,2},{58,1}}; // {{3,2},{4,3},{4,4},{2,5}} {{21,2},{1,2},{12,5},{7,2},{35,3},{32,2},{80,2},{91,5},{92,3},{27,3},{19,1},{37,3},{85,2},{33,4},{25,1},{91,4},{44,3},{93,3},{65,4},{82,3},{85,5},{81,3},{29,2},{25,1},{74,2},{58,1},{85,1},{84,2},{27,2},{47,5},{48,4},{3,2},{44,3},{60,5},{19,2},{9,4},{29,5},{15,3},{1,3},{60,2},{63,3},{79,3},{19,1},{7,1},{35,1},{55,4},{1,4},{41,1},{58,5}}
    //cout<<mostPoints(questions)<<endl;
    //vector<int>nums={-6,40,-38,-36,-36,-4,-38,-43,8}; int k=2, x=2; // nums={1,-1,-3,-2,3}; int k=3, x=2  {5} 1 1 nums={-3,1,2,-3,0,-3}; int k=2, x=1 {-46,-34,-46}; int k=3, x=3
    //getSubarrayBeauty(nums,k,x); // 重复元素太多，TLE, use map
    //vector<int>nums1 ={2,1}, nums2={1,2,1,3,3,2}; // nums1 ={3,3}, nums2={3} nums1 ={1,1,2,1,2}, nums2={1,3,2,3,1} nums1 ={1,4,2}, nums2={1,2,4} {2,5,1,2,5}, nums2={2,5,1,2,5}
    //maxUncrossedLines(nums1,nums2);
    //string s="ADOBECODEBANC", t="ABC"; //   s="ADOBECODEBANC", t="ABC" s="cabwefgewcwaefgcf", t="cae" s="aaaaaaaaaaaabbbbbcdd", t="abcdd"
    //cout<< minWindow(s,t)<<endl;
    //vector<int> nums = {1,0,1,4,1,4,1,2,3}; int target=7; // 1,0,3,4,3  {1} {0,0,1,1}  0,1,6,6,4,4,6 {1,2,3,2,2} {3,3,3,1,2,1,1,2,3,3,4}
    //totalFruit(nums);
    //minSubArrayLen(target, nums);
    //string s ="xywrrmp", t="xywrrmu#p";
    //backspaceCompare(s,t);
    //vector<int>nums ={1}; int val=1;
    // removeElement(nums,val);
    // string s ="abcz"; int k=26;
    // cout<<smallestBeautifulString(s,k);
    // int n = 2; vector<vector<int>> meetings = {{0,10},{1,2},{12,14},{13,15}};
    // int res=mostBooked(n, meetings); // {{0,10},{1,5},{2,7},{3,4}}  n=2
     // (72/82)runtime error: signed integer overflow: 2147400001 + 300000 cannot be represented in type 'int'
   // vector<int> res=maxSlidingWindow(nums, k);
    // ***
    // long long a = (static_cast<int64_t>(pow(2, 54)) - 1) % mod; // int64_t is long long
    // ***
    // -7,-8,7,5,7,1,6,0
    
    /*n =
10*/
