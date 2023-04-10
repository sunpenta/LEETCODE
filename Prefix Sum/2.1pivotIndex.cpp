// 中位数的位置-prefix sum  l-724
// index: sum[0,index)=sum(index,n-1], 若找不到index, 返回-1
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int pivotIndex(vector<int>& nums);

int main()
{
    vector<int> nums={1,7,3,6,5,6}; // input
    cout<<pivotIndex(nums)<<endl; // output:3 1+7+3 = 5+6 =11
    system("pause");
}

int pivotIndex(vector<int>& nums)
{
    int n=nums.size();
    int leftsum=0, rightsum=accumulate(nums.begin(),nums.end(),0);
    for (int i=0; i<n; i++)
    {
        rightsum-=nums[i];
        if (leftsum==rightsum) return i;
        leftsum+=nums[i];
    }
    return -1;
}