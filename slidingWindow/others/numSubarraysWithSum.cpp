/* Binary Subarray With Sum l-930
时间复杂度：O(n) */
#include <iostream>
#include <vector>
using namespace std;
int numSubarraysWithSum(vector<int> &nums, int goal);

int main()
{
    vector<int> nums = {0, 0, 0, 0, 0}; int goal = 0; // input
    int res = numSubarraysWithSum(nums, goal);
    cout << res << endl; // 15
    return 0;
}

int atMost(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;
    int res = 0, n = nums.size(), i = 0, j = 0;
    for (; j < n; j++)
    {
        goal -= nums[j];
        while (goal < 0)
            goal += nums[i++];
        res += j - i + 1;
    }
    return res;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return atMost(nums, goal) - atMost(nums, goal - 1);
}