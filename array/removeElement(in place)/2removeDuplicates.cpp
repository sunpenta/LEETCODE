// 删除有序数组的重复元素 - 快慢指针  l-26
// -> 无重复元素个数k(保留1个)；原数组前k个是无重复元素(相对顺序不变)
// 时间复杂度：O(n) 空间复杂度:O(1)
#include <iostream>
#include <vector>
using namespace std;
int deleteDuplicates(vector<int>& nums);

int main()
{
    vector<int> nums={0,0,1,1,1,2,2,3,3,4}; // input
    int res=deleteDuplicates(nums); // output: 5 {0,1,2,3,4,2,2,3,3,4}
    cout<<res<<endl; 
    for (int num:nums)
        cout<< num << " ";
    return 0;  
}

int deleteDuplicates(vector<int>& nums)
{
    int i=1, j=1;
    for (; j<nums.size(); j++)
    {
        if (nums[j]!=nums[j-1]) 
            nums[i++]=nums[j];
    }
    return i;
}