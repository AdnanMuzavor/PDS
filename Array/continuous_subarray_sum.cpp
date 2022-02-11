/*
523. Continuous Subarray Sum
Medium

1421

202

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
// Better then brute force i.e prefix sum and O(n^2)
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        // if(nums.size()==1 && nums[0]==k) return false;
        // else if(nums.size()==1 && nums[0]!=k) return false;
        vector<int> sums(nums.size(), 0);
        int sum = 0;
        int i = 0;
        for (auto e : nums)
        {
            sum += e;
            sums[i] = sum;
            i++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (i <= 0)
                    sum = sums[j];
                else
                    sum = sums[j] - sums[i - 1];
                if ((sum == k || sum % k == 0) && j - i + 1 >= 2)
                    return true;
            }
        }
        return false;
    }
};