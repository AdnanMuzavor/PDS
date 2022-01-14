/*
56. Merge Intervals
Medium

11511

472

Add to List

Share
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.



Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if (n == 1)
            return intervals;
        vector<vector<int>> op;
        if (n == 0)
            return op;
        sort(intervals.begin(), intervals.end());
        vector<int> pair = intervals[0];
        for (auto e : intervals)
        {
            if (e[0] <= pair[1])
            {
                pair[1] = max(e[1], pair[1]);
            }
            else
            {
                op.push_back(pair);
                pair = e;
            }
        }
        op.push_back(pair);
        return op;
    }
};