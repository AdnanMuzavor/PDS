/*
16. 3Sum Closest
Medium

5164

229

Add to List

Share
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.



Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int minidiff = INT_MAX;
        int resultsum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int l = i + 1, h = nums.size() - 1;
            while (l < h)
            {
                // Finding sum of current triplets
                int currsum = nums[i] + nums[l] + nums[h];

                // if currsum matches target we returm it
                if (currsum == target)
                    return currsum;

                // checking if currsum-target difference is minimum
                // if so we'll update resultsum as well as well as min diff
                if (abs(target - currsum) < minidiff)
                {
                    minidiff = abs(target - currsum);
                    resultsum = currsum;
                }

                if (currsum < target)
                {
                    l++;
                }
                else if (currsum > target)
                {
                    h--;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return resultsum;
    }
};