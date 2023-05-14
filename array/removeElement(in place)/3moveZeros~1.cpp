// 移动0元素到数组尾端 - 快慢双指针  l-283
// 要求：相对顺序不变
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
// 先把非0元素放到数组前端；再在非零元素后填充0
void moveZeros(vector<int>& nums)
{
    int i=0, j=0;
    for (; j<nums.size(); ++j)
    {
        if (nums[j]!=0)
            nums[i++]=nums[j];
    }
    for (; i<nums.size(); i++)
        nums[i]=0;
}