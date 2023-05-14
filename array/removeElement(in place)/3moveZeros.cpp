// 移动零元素到数组尾端 - 快慢双指针  l-283
// 要求：原数组非零元素相对顺序不变
// 时间复杂度：O(n) 空间复杂度:O(1)
#include <iostream>
#include <vector>
using namespace std; // 忘记命名空间
void moveZeros(vector<int>& nums);

int main()
{
    vector<int> nums={0,1,0,3,12}; // input
    moveZeros(nums); // output {12,1,3,0,0}
    return 0;
}

void moveZeros(vector<int>& nums)
{
    int i=0, j=0;
    for (; j<nums.size(); ++j)
    {
        if (nums[j]!=0)
            nums[i++]=nums[j];
    }
    for (int k=i; k<nums.size(); k++)
        nums[k]=0;
}