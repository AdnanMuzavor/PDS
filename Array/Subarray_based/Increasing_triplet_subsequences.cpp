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
// optimised
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= min1)
            {
                min1 = nums[i];
            }
            else if (nums[i] <= min2)
            {
                min2 = nums[i];
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

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
// Better then brute force
class Solution
{
public:
    bool ans = false;
    int flag = -1;
    bool permute(vector<vector<int>> curr, vector<int> nums, int start)
    {
        if (curr.size() >= 3)
        {
            if (curr[0][1] < curr[1][1] && curr[1][1] < curr[2][1])
            {
                if (curr[0][0] < curr[1][0] && curr[1][0] < curr[2][0])
                {
                    ans = true;
                    flag = 1;
                }
            }
            return false;
        }
        for (int i = start; i < nums.size(); i++)
        {
            if (i >= 1 && i != start && nums[i] == nums[i - 1])
                continue;
            vector<int> v;
            v.push_back(i);
            v.push_back(nums[i]);
            curr.push_back(v);
            bool ans1 = permute(curr, nums, i + 1);
            curr.pop_back();
            if (ans1 == true)
                return true;
        }
        return false;
    }
    bool increasingTriplet(vector<int> &nums)
    {

        vector<vector<int>> curr;
        permute(curr, nums, 0);
        return ans;
    }
};