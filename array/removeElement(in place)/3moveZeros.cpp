// 移动零元素到数组尾端 - 快慢双指针  l-283
// 前面零与后面非零交换，原数组元素相对顺序不变
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
    int i=0, j=nums.size()-1;
    while (i<j)
    {
        if (nums[i]==0)
        {
            if (nums[j]!=0)
                swap(nums[i++],nums[j--]);
            else
                j--;
        }         
        else
        {
            i++, j--;
        }
    }
}