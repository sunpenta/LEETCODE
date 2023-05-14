// 子数组积小于k - slide window  l-713
// subarray:连续; nums.length∈[1,3e4], nums[i]∈[1,1000], k∈[0,1e6]
#include <iostream>
#include <vector>
using namespace std;
int numSubarrayProductLessThanK(vector<int>& nums, int k);

int main()
{
    vector<int> nums={10,5,2,6}; int k=100; // input
    cout<<numSubarrayProductLessThanK(nums,k)<<endl; // output:8 {10}, {5}, {2}, {6}, 
    system("pause");                                 // {10,5}, {5,2}, {2,6}, {5,2,6}
}

int numSubarrayProductLessThanK(vector<int>& nums, int k)
{
    int n=nums.size();
    if (k==0) return 0;

    int i=0, j=0, product=1, ans=0;
    while (j<n) // [i,j]
    {
        product*=nums[j];
        while (i<=j && product>=k) // note: <= >=
        {
            product/=nums[i];
            ++i; // note: ++
        }
        ans+=(j-i+1);
        ++j;
    }
    return ans;
}
