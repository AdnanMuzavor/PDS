/*
1288. Remove Covered Intervals
Medium

1105

33

Add to List

Share
Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.



Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        // to keep track of no of ele to be removed
        int ans = 0;
        // Taling up a pair
        vector<int> pair(2, 0);
        pair[0] = intervals[0][0];
        pair[1] = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            // When pair covers the interval
            if (intervals[i][0] >= pair[0] && intervals[i][1] <= pair[1])
            {

                // Assume we'll be removing current pair
                ans++;
            }
            // When interval covers the pair
            else if (intervals[i][0] <= pair[0] && intervals[i][1] > pair[1])
            {
                // Assume we wil be removing pair and making current intrval as new pair
                ans++;
                pair[0] = intervals[i][0];
                pair[1] = intervals[i][1];
            }
            // If above conditions don't met there is no-overlapping
            else
            {

                pair[0] = intervals[i][0];
                pair[1] = intervals[i][1];
            }
        }
        return intervals.size() - ans;
    }
};