/*
560. Subarray Sum Equals K
Medium

11243

359

Add to List

Share
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.



Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
*/
//REFER NEETCODE VIDEO FOR INTUITION
#include <bits/stdc++.h>
using namespace std;
// optimised(tech dose)
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int cum = 0;                 // cumulated sum
        unordered_map<int, int> rec; // prefix sum recorder
        int cnt = 0;                 // number of found subarray
        rec[0]++;                    // to take into account those subarrays that begin with index 0
        for (int i = 0; i < nums.size(); i++)
        {
            cum += nums[i];
            cnt += rec[cum - k];
            rec[cum]++;
        }
        return cnt;
    }
};
// BRUTE FORCE
class Solution
{
public:
    bool ans(vector<int> nums, int i, int j, int k)
    {
        int sum = 0;
        for (int k = i; k <= j; k++)
        {
            sum += nums[k];
        }
        if (sum == k)
            return true;
        return false;
    }
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (ans(nums, i, j, k))
                    count++;
            }
        }
        return count;
    }
};

