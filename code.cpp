#include <bits/stdc++.h>
using namespace std;
    bool ispal(string s, int i)
    {
        return (i>0 && s[i]==s[i-1] || i>1 && s[i]==s[i-2]);
    }
    string smallestBeautifulString(string s, int k) {
        int n=s.length();
        for (int i=n-1; i>=0; --i)
        {
            ++s[i];
            while (ispal(s,i))
            {
                ++s[i];
            }

            if (s[i] < 'a'+k)
            {
                for (int i=i+1; i<n; ++i)
                    for (s[i]='a'; ispal(s,i); ++s[i]) ;    
                
                return s;
            }
        }
        return "";
    }
    
int main()
{
    string s ="abcz"; int k=26;
    cout<<smallestBeautifulString(s,k);
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