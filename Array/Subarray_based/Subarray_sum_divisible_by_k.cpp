/*
974. Subarray Sums Divisible by K
Medium

2522

132

Add to List

Share
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.



Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0
*/
#include <bits/stdc++.h>
using namespace std;
// brute force
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int c = 0;
        int s = 0;
        vector<int> m(nums.size(), 0);
        int i = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s += nums[i];
            m[i] = s;
            i++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (i <= 0)
                    s = m[j];
                else
                    s = m[j] - m[i - 1];
                if (s % k == 0)
                    c++;
            }
        }
        return c;
    }
};
// optimised approach(I failed in thinking for one test case when remainder==0)
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> count;
        count[0] = 1;
        int s = 0, ans = 0;
        for (auto e : nums)
        {
            s += e;
            int rem = s % k;
            if (rem < 0)
                rem += k;
            cout << s << endl;
            ans += count[rem];
            count[rem]++;
        }
        return ans;
    }
};