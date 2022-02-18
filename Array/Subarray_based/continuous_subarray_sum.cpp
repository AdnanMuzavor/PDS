/*
523. Continuous Subarray Sum
Medium

1489

216

Add to List

Share
Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.



Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false
*/
#include <bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        vector<int> sum(nums.size(), 0);
        int s = 0, i = 0;
        for (auto e : nums)
        {
            s += e;
            sum[i++] = s;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (i != 0)
                {
                    int s = sum[j] - sum[i - 1];
                    // cout<<"s: "<<s<<endl;
                    if (s % k == 0)
                        return true;
                }
                else
                {
                    int s = sum[j];
                    // cout<<"s: "<<s<<endl;
                    if (s % k == 0)
                        return true;
                }
            }
        }
        return false;
    }
};

// optimised
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(), sum = 0, pre = 0;
        unordered_set<int> modk;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            int mod = k == 0 ? sum : sum % k;
            if (modk.count(mod))
                return true;
            modk.insert(pre);
            pre = mod;
        }
        return false;
    }
};