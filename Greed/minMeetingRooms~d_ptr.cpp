// 最少会议室 - greedy  l-253(会员)
// intervals[i]:[si,ei]:si:start time, ei:end time;length⋿[1,1e4]; 时间复杂度:O(nlogn), 空间复杂度:O(n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minMeetingroomss(vector<vector<int>>& intervals);

int main()
{
    vector<vector<int>> intervals={{1, 3}, {8, 10},{2, 6},  {9, 15}, {12, 14}}; // input
    cout<<minMeetingroomss(intervals)<<endl; // output:3 {1,3},{8,10},{12,14}  {2,6},{9,15}
    return 0;
}

int minMeetingroomss(vector<vector<int>>& intervals)
{
    vector<int> start, end;
    int n=intervals.size();
    for (int i=0; i<n; ++i)
    {
        start.emplace_back(intervals[i][0]);
        end.emplace_back(intervals[i][1]);
    }
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());

    int i=1, j=0, rooms=1, res=1;
    while (i<n && j<n)
    {
        if (start[i]<end[j])
        {
            ++rooms;
            ++i;
        }
        else
        {
            --rooms; // ?
            ++j;
        }
        res=max(res,rooms); // max?
    }
    return res;
}