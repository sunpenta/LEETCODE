#include <bits/stdc++.h>
using namespace std;
int minbike(vector<int>& heights, int m);
int main()
{
    int m, n; vector<int>heights;
    while(cin>>m>>n)
    for (int i=0; i<n; i++)
    {
        cin>>heights[i];
    }
    cout<<minbike(heights,m)<<endl;
}

int minbike(vector<int>& heights, int m)
{
    int n=heights.size();
    sort(heights.begin(),heights.end());
    int left=0, right=n-1;
    int ans=0; // min num of bikes
    while (left<right)
    {
        if (heights[left]+heights[right]>m)
        {
            right--;ans++;
        }
        else
        {
            left++; right--; ans++;
        }
    }
    return ans;
}