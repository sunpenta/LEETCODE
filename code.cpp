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
        for (; j<=m && i<m; ++j)
        {
            if (needlen) // needlen<0 needlen>0 
            {
                if (j==m) break;
                --mpt[s[j]];
                if (mpt[s[j]]>=0)
                    --needlen;         
            }
            else
            {
                while (needlen==0)
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
        }
        return minlen==1e5+1?"":s.substr(begin,minlen);  
    }
int main()
{
    string s="ADOBECODEBANC", t="ABC"; //   s="ADOBECODEBANC", t="ABC" s="cabwefgewcwaefgcf", t="cae" s="aaaaaaaaaaaabbbbbcdd", t="abcdd"
    cout<< minWindow(s,t)<<endl;
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
    return 0;
    /*n =
10*/
}