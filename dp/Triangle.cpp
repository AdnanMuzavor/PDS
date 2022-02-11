/*
120. Triangle
Medium

4381

371

Add to List

Share
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.



Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        // Getting rows/no of layers
        int layer = triangle.size();
        // each column will have elements equal to layer+1
        // i.e layer 2 will have 2+1 i.e 3 elements
        // count them as 0th, 1st and 2nd

        // Initialising dp with last column
        vector<int> dp(triangle.back());

        // Since last layer is initialised we can start from second last row i.e
        // layer -1 is first row so layer-2 is second row
        for (int i = layer - 2; i >= 0; i--)
        {
            // Processing each elemt in this layer
            for (int j = 0; j <= i; j++)
            {
                // Since in dp we have last layer, for each elemet in current layer we take
                // min element at below layer as per condition i.e j, j+1th element
                // and then add current elemet and store correponding to it
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};