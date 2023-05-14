// nextPermutation l-31
// 时间复杂度:O(n) 空间复杂度：O(1)
# include<iostream>
# include <vector>
using namespace std;
void nextPermutation(vector<int>& nums);

int main()
{
    vector<int>nums{2,3,5,4,1}; // input
    nextPermutation(nums); // output
    for (int num:nums)
        cout<<num<<" ";
    cout<<endl;
    return 0;
}

void nextPermutation(vector<int>& nums)
{

}