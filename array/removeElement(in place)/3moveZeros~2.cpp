// 移动0元素到数组尾端 - 快慢指针冒泡  l-283
# include<iostream>
# include<vector>
using namespace std;
void moveZeros(vector<int>& nums);

int main()
{
    vector<int> nums={0,1,0,3,12}; // input
    moveZeros(nums); // output: {1,3,12,0,0}
    return 0;
}

void moveZeros(vector<int>& nums)
{
    int i=0, j=0;
    for (; j<nums.size(); j++)
    {
        if (nums[j]!=0)
            swap(nums[i++],nums[j]);
    }
}