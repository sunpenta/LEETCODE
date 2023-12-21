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

// 该for循环解法与第一种while的解法思路相同，写法不同
vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();
    vector<int> sorted(n);
    int i = 0, j = n - 1;
    for (int k = n - 1; k >= 0; k--)
    {
        if (abs(nums[i]) < abs(nums[j]))
            sorted[k] = nums[j] * nums[j--];
        else
            sorted[k] = nums[i] * nums[i++];
    }
    return sorted;
}