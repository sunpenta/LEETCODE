/*Count Numbers Of Nice Subarrays l-1248
A continuous subarray is called nice if there are k odds numbers on it. */
#include <iostream>
#include <vector>
using namespace std;
int numberOfSubarrays(vector<int> &nums, int k);

int main()
{
    vector<int> nums{2,2,2,1,2,2,1,2,2,2}; int k=2;
    int res = numberOfSubarrays(nums,k);
    cout << res << endl;
    return 0;
}

int numberOfSubarrays(vector<int> &nums, int k)
{
    int n = nums.size(), res = 0, count = 0, i = 0, j = 0;
    for (; j < n; j++)
    {
        if (nums[j] % 2)
        {
            --k;
            count =0;
        }

        while (k == 0)
        {
            k += nums[i++] & 1;
            count++;
        }
        res+=count;
    }
    return res;
}