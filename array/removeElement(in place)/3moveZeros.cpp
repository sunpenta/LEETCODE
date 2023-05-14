// 移动零元素到数组尾端 - 相向双指针  l-283
// 前面零与后面非零交换，改变了原数组元素相对顺序
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
    for (; i<j; i++)
    {
        if (nums[i]==0 && nums[j]!=0)
            swap(nums[i],nums[j--]);
        else if (nums[i]==0 && nums[j]==0)
            j--;
    }
}