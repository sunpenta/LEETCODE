// find k elements closest to x - binary search  l-658
// 原数组已排序;  a closer to b:|a - x| < |b - x|, 或 |a - x| == |b - x| and a < b
#include <iostream>
#include <vector>
using namespace std;
vector<int> findClosestElements(vector<int>& nums, int k, int x);

int main()
{
    vector<int> nums={1,2,3,4,5}; int k=4, x=-1; // input;
    vector<int> res=findClosestElements(nums,k,x);
    for (int i:res) cout<<i<<" "; // output: {1,2,3,4}
    return 0;
}

vector<int> findClosestElements(vector<int>& nums, int k, int x)
{
    int left=0, right=nums.size()-k;
    while (left<right)
    {
        int mid=(left+right)/2;
        if (x-nums[mid]>nums[mid+k]-x) // [mid,mid+k)
            left=mid+1;
        else
            right=mid;
    }
    return vector<int>(nums.begin()+left,nums.begin()+left+k); // [left,left+k)
}
