// 房屋盗窃 IV  l-2560
// 不能偷相邻房屋，至少偷k个房子 -> 最小偷窃袋子容量; 
#include <iostream>
#include <vector>
using namespace std;
int minCapability(vector<int>& nums, int k);

int main()
{
    vector<int> nums={2,3,5,9}; int k=2; // input
    int res=minCapability(nums,k); // output:5
    cout<<res<<endl;
    return 0;
}

int minCapability(vector<int>& nums, int k)
{
    auto check=[&](int mid) ->bool
    {
        int count=0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]<=mid)
            {
                count++;
                i++;
            }
        }
        return count>=k;
    };

    int left=0, right=1e9;
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