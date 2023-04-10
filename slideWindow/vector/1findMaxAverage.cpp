// 子数组的最大平均值I-slide window  l-643
// -> double
# include <bits/stdc++.h>
using namespace std;
double maxMaxAverage(vector<int>& nums, int k);

int main()
{
    vector<int> nums={1,12,-5,-6,50,3}; int k=4; // input
    cout<<maxMaxAverage(nums,k)<<endl; // output
    system("pause");
}

double maxMaxAverage(vector<int>& nums, int k)
{
    int n=nums.size(); 
    double sum=0, maxsum=0; // note:double
    for (int i=0; i<k; i++)
        sum+=nums[i];
    maxsum=sum;

    for (int i=k; i<n; i++)
    {
        sum+=nums[i]-nums[i-k];
        maxsum=max(maxsum,sum);
    }
    return maxsum/k;
}