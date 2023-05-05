// 最少会议室 - greedy  l-253(会员)
// intervals[i]:[si,ei]:si:start time, ei:end time;length⋿[1,1e4]; 时间复杂度:O(n)
#include <iostream>
using namespace std;
int minMeetingRooms(vector<vector<int>>& intervals);

int main()
{
    vector<vector<int>> intervals={{1, 3}, {8, 10},{2, 6},  {9, 15}, {12, 14}}; // input
    cout<<minMeetingRooms(intervals)<<endl; // output:3
    return 0;
}

int minMeetingRooms(vector<vector<int>>& intervals)
{
    vector<int> start, end;
    int n=intervals.size();
    for (int i=0; i<n; ++i)
    {
        start.emplace_back(internals[i][0]);
    }
     for (int i=0; i<n; ++i)
    {
        end.emplace_back(internals[i][1]);
    }
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    int i=0, j=0, rooms=1, res=INT_MAX; 
    while (i<n && j<n)
    {
        if (start[i]<end[j])
        {
            ++room;
            ++i;
        }
        else
        {
            --room;
            ++j;
        }
        res=max(res,room);
    }
    return res;
}