// 排序数组的平方 - 双指针  l-977
// 时间复杂度:O(n) 空间复杂度:O(1)
#include <iostream>
#include <vector>
using namespace std;
vector<int> sortedSquares(vector<int> &nums);

int main()
{
    vector<int> nums = {-3, -2, 0, 2, 4};  // input
    vector<int> res = sortedSquares(nums); // output {0,4,4,9,16}
    for (int num : res)
        cout << num << " ";
    return 0;
}

vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();
    vector<int> sorted(n);
    int i = 0, j = n - 1;
    while (i <= j) // 忘记等号
    {
        if (abs(nums[i]) < abs(nums[j])) // 比较绝对值，左右绝对值都加
        {
            sorted[--n] = nums[j] * nums[j]; // 写成前缀减，因为下标从n-1开始
            --j;
        }
        else
        {
            sorted[--n] = nums[i] * nums[i];
            ++i;
        }
    }
    return sorted;
}