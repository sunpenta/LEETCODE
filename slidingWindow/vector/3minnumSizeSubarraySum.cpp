// 最小子数组和长度  l-209
#include <iostream>
#include <vector>
using namespace std;
int minSubArrayLen(int target, vector<int> &nums);

int main()
{
    vector<int> nums{2, 3, 1, 2, 4, 3};
    int target = 7; // input
    int len = minSubArrayLen(target, nums);
    cout << len << endl;
    return 0;
}

int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    int len = INT_MAX, sum = 0, i = 0, j = 0;
    while (i <= j && j < n)
    {
        sum += nums[j++];
        while (sum >= target)
        {
            len = min(len, j - i);
            sum  -= nums[i++];
        }    
    }
    return len == INT_MAX ? 0 :len;
}