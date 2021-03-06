/*
152. Maximum Product Subarray
Medium

10366

321

Add to List

Share
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.



Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        long long int mini = nums[0];
        long long int maxi = nums[0];
        long long int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(maxi, mini);
            maxi = max((long long int)nums[i], maxi * (long long int)nums[i]);
            mini = min((long long int)nums[i], mini * (long long int)nums[i]);
            if (maxi > ans)
                ans = maxi;
        }
        return ans;
    }
};