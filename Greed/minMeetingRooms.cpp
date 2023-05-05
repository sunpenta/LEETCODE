// 最少会议室 - greedy  l-253(会员)
// intervals[i]:[si,ei]:si:start time, ei:end time;length⋿[1,1e4]; 时间复杂度:O(n)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
    sort(intervals.begin(), intervals.end()); // by start-time

    priority_queue<int, vector<int>, greater<>> pq; // by end-time
    for (auto interval:intervals)
    {
        if (!pq.empty() && interval[0]>=pq.top())
            pq.pop();
        pq.push(interval[1]);
    }
    return pq.size();
}