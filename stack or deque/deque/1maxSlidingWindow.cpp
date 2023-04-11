// slide window的最大值 - 单调deque  l-239
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k);

int main()
{
    vector<int> nums={1,2,3,3,-1,7,6}; int k=3; // input
    vector<int> res=maxSlidingWindow(nums,k); // ouput
    for (int i:res) cout<<i<<" ";
    system("pause");
}

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    int n=nums.size();
    deque<int> dq; // <index> front 大->小 back
    vector<int> res;
    for (int i=0; i<n; i++)
    {
        if (!dq.empty() && dq.front()==i-k) dq.pop_front();
        while (!dq.empty() && nums[i]>nums[dq.back()]) dq.pop_back();
        dq.emplace_back(i);
        if (i>=k-1) res.emplace_back(dq.front());
    }
    return res;
}