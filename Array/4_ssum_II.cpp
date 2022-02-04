/*
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0


Example 1:

Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
Example 2:

Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
Output: 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int c = 0;
        unordered_map<int, int> m1;
        // Finding all sums which we can get using first 2 vectors
        for (auto e1 : nums1)
        {
            for (auto e2 : nums2)
            {
                m1[e1 + e2]++;
            }
        }
        // we know that if a+b+c+d=0 thn a+b=0-c-d or a+b=-(c+d)
        // Therefore wec hec k for second half and if it exists
        // We increment count by frequency of second half as that many times it's possible
        // to have sum=0
        for (auto e3 : nums3)
        {
            for (auto e4 : nums4)
            {
                if (m1[0 - e3 - e4])
                {
                    c += m1[0 - e3 - e4];
                }
            }
        }
        return c;
    }
};