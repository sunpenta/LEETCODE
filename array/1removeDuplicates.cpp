// 删除有序数组中的重复项 - 新数组 l-26  -Linked List/delete/deleteDuplicates
#include <bits/stdc++.h>
using namespace std;
vector<int> deleteDuplicates(vector<int>& nums);

int main()
{ 
    vector<int> nums{1,1,2}; // 输入

    vector<int>ans;
    int n=nums.size();
    for (int i=0;i<n;i++)
    {
        if (i<n-1 && nums[i]==nums[i+1]) 
            continue;
        ans.push_back(nums[i]);
    }
    int k=ans.size();

    for (int i=0;i<k;i++)
        nums[i]=ans[i];

    // 输出
    cout<<k<<endl;
    for (auto num:nums) 
        cout<< num <<" ";
    system("pause");  
}

vector<int> deleteDuplicates(vector<int>& nums)
{

}