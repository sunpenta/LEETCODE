// 最少会议室 - greedy  l-253(会员)
// intervals[i]:[si,ei]:si:start time, ei:end time;length⋿[1,1e4]; 时间复杂度:O(n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minMeetingRooms(vector<vector<int>>& intervals);

int main()
{
    vector<vector<int>> intervals={{1, 3}, {2, 6}, {8, 10}, {9, 15}, {12, 14}}; // input
    cout<<minMeetingRooms(intervals)<<endl; // output:3
    return 0;
}

int minMeetingRooms(vector<vector<int>>& intervals)
{
    int n=intervals.size();
    int minRooms=1;
    sort(intervals.begin(),intervals.end(),[](const vector<int>& a, const vector<int>& b){return a[1]<b[1];});
    for (int i=1; i<n; ++i)
    {
        if (intervals[i][0]>intervals[i-1][1])
            continue;
        else
            ++minRooms;
    }
    return minRooms;
}