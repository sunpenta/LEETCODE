// 移除元素  l-27
// ->移除val后的元素数k, nums原数组前k位是移除后元素
# include<iostream>
# include<vector>
using namespace std;
int removeElement(vector<int>& nums, int val);

int main()
{
    vector<int> nums={0,1,2,3,3,0,4,2}; int val=2; // input;
    int res=removeElement(nums,val);
    cout<<res<<endl;
    return 0; 
}

int removeElement(vector<int>& nums, int val)
{
    int i=0, j=0;
    for (; j<nums.size(); j++)
    {
        if (nums[j]!=val)
            nums[i++]=nums[j];
        
    }
    return i;
}