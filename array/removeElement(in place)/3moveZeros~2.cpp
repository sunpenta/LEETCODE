// 移动0元素到数组尾端 - 冒泡  l-283
# include<iostream>
# include<vector>
using namespace std;
void moveZeros(vector<int>& nums);

int main()
{

}

void moveZeros(vector<int>& nums)
{
    for (int i=0; i<nums.size()-1; i++)
    {
        if (nums[i]==0)
            swap(nums[i],nums[i+1]);
    }
}