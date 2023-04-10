// 吃香蕉-binary search  l-875
// piles.length∈[1,1e4], piles[i]∈[1,1e9]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minEatingSpeed(vector<int>& piles, int h);

int main()
{
    vector<int> piles={30,11,23,4,20}; int h=5; // input
    cout<<minEatingSpeed(piles,h)<<endl; // output:30
    system("pause");
}
// speed is k, eat all piles
bool check(vector<int>& piles, int h, int k)
{
    
}
int minEatingSpeed(vector<int>& piles, int h)
{
    int left=1, right=*max_element(piles.begin(),piles.end());

}