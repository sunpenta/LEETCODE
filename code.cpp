#include <bits/stdc++.h>
using namespace std;
vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
    int m=queries.size(), count=0;
    vector<int> res(m), nums(n,0);
    for (int i=0; i<m; ++i)
    {
        int j=queries[i][0];
        int pre=nums[j];
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
    int n = 4; vector<vector<int>> queries = {{0,2},{1,2},{3,1},{1,1},{2,1}};
    vector<int> res=colorTheArray(n,queries);
    cout<<endl;
    // ***
    // long long a = (static_cast<int64_t>(pow(2, 54)) - 1) % mod; // int64_t is long long
    // ***
    return 0;
}