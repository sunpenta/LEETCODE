// 排序数组的平方 - 双指针  l-977
// 时间复杂度:O(n) 空间复杂度:O(1)
# include<iostream>
# include<vector>
using namespace std;
vector<int> sortedSquares(vector<int>& nums);

int main()
{

}

vector<int> sortedSquares(vector<int>& nums)
{
    int n=nums.size();
    vector<int> sorted(n);
    int i=0, j=n-1;
    while (i<j)
    {
        if (abs(nums[i]<nums[j]))
        {
            sorted[n--]=nums[j--];
        }
        else
        {
            sorted[n--]=nums[i++];
        }
    }
}