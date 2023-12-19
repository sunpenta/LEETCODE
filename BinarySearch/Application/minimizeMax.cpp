// 最小最大的数字对差值  l-2616
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minimizeMax(vector<int>& nums, int p);

int main()
{
    vector<int> nums={8,9,1,5,4,3,6,4,3,7}; int p=4; // input
    int res=minimizeMax(nums,p); // output:1
    cout<<res<<endl;
    return 0;
}

int minimizeMax(vector<int>& nums, int p)
{
    int n=nums.size();
    sort(nums.begin(), nums.end());
    auto check=[&](int mid)
    {
        int count=0;
        for (int i=1; i<n; i++)
        {
            if (nums[i]-nums[i-1]<=mid)
            {
                count++;
                i++;
            }
        }
        return count>=p;
    };

    int left=0, right=nums[n-1]-nums[0];
    while (left<right)
    {
        int mid=(left+right)/2;
        if (check(mid))
            right=mid;
        else
            left=mid+1;
    }
    return left;
}