#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void sort1(vector<int> &nums);
int main()
{
    vector<int> nums={3,1,2,-1,0,-5,-2,0,0};
    for (int num:nums)
        cout << num << " ";
    cout << endl;
    sort1(nums);
    for (int num:nums)
        cout << num << " ";
    cout << endl;
    return 0;
}

void sort1(vector<int> &nums)
{
    int n=nums.size(), left=0, right=0;
    while (right < n)
    {
        if (nums[right] < 0)
            swap(nums[left++],nums[right]);
        right++;
    }

    right = left;
    while (right < n)
    {
        if (nums[right] == 0)
            swap(nums[left++],nums[right]);
        right++;
    }   
}
