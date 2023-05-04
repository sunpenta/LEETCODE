// 吃香蕉 - binary search  l-875
// piles.length∈[1,1e4], piles[i]∈[1,1e9], h∈[piles.length,1e9]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minEatingSpeed(vector<int>& piles, int h);

int main()
{
    vector<int> piles={30,11,23,4,20}; int h=5; // input
    cout<<minEatingSpeed(piles,h)<<endl; // output:30
    return 0;
}
// speed is k, can eat all piles?
bool check(vector<int>& piles, int h, int k)
{
    int time=0;
    for (int pile:piles)
        time+=(pile-1)/k+1; // 同ceil(double(pile)/double(k))
    return time<=h;
}
int minEatingSpeed(vector<int>& piles, int h)
{
    int left=1, right=*max_element(piles.begin(),piles.end());
    while (left<right)
    {
        int mid=(left+right)/2;
        if (check(piles,h,mid))
            right=mid;
        else
            left=mid+1;
    }
    return left;
}