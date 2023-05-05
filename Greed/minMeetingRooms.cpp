// 最少会议室 - greedy  l-253
// intervals[i]:[si,ei]:si:start time, ei:end time; 时间复杂度:
#include <iostream>
#include <vector>
using namespace std;
int minMeetingRooms(vector<vector<int>>& intervals);

int main()
{
    vector<vector<int>> intervals={{0, 30},{5, 10},{15, 20}}; // input
    cout<<minMeetingRooms(intervals)<<endl; // output:2
    return 0;
}

bool cmp(const vector<vector<int>>& a, const vector<vector<int>>& b)
{
    
}
int minMeetingRooms(vector<vector<int>>& intervals)
{
    int minRooms=1;
    int n=intervals.size();

    sort(intervals.begin(),intervals.end(),cmp);
    for (int i=1; i<n; ++i)
    {
        if (intervals[i][0]>intervals[i-1][1])
            continue;
        else
            ++minRooms;
    }
    return minRooms;
}