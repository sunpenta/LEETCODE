#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void bubble_sort(vector<int>& nums); // 从小到大
int main()
{
    vector<int> nums={2,3,4,1};
    bubble_sort(nums);
    for (int num:nums)
    {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
void bubble_sort(vector<int>& nums)
{
    int n=nums.size();
    for (int i=n-2; i>=0; i--)
    {
        for (int j=i+1; j<n; j++)
        {
            if (nums[j]<nums[j-1])
                swap(nums[j],nums[j-1]);
        }
    }
}