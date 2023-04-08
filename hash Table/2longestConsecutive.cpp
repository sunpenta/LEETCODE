// 最长连续序列-hash  l-128
// num.length∈[0,1e5]; 时间复杂度:O(n)
#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int>nums);

int main()
{
    vector<int>nums={100,4,4,10,1,3,2}; // 输入
    cout<<longestConsecutive(nums)<<endl; // 输出:4 {1,2,3,4}
    system("pause");
}

int longestConsecutive(vector<int>nums)
{
    unordered_set<int>hash(nums.begin(),nums.end());
    int maxlen=0;
    for (int num:hash)
    {
        if (!hash.count(num-1))
        {
            int curnum=num, len=1;
            while (hash.count(++curnum))
            {
                len++;
            }
            maxlen=max(maxlen,len);
        }
    }
    return maxlen;
}