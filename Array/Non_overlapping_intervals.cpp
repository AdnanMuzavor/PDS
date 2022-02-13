/*
435. Non-overlapping Intervals
Medium

3482

94

Add to List

Share
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.



Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/
#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 1)
            return 0;
        // Sorting array based on second element of interval
        sort(intervals.begin(), intervals.end(), comp);
        int ans = -1;
        vector<int> pair = intervals[0];
        // If 0th element i.e lower bound>pair's upper bound then it'll help in merging
        for (auto e : intervals)
        {
            if (e[0] < pair[1])
            {
                ans++;
            }
            else
                pair = e;
        }
        return ans;
    }
};