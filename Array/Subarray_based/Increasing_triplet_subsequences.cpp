/*
334. Increasing Triplet Subsequence
Medium

3548

202

Add to List

Share
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.



Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
*/
#include <bits/stdc++.h>
using namespace std;
// BRUTE FORCE

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {

        int n = nums.size();
        if (n < 3)
            return false;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (i < j && j < k)
                    {
                        if (nums[i] < nums[j] && nums[j] < nums[k])
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};