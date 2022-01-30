/*
1089. Duplicate Zeros
Easy

1465

483

Add to List

Share
Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.



Example 1:

Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void duplicateZeros(vector<int> &nums)
    {
        vector<int> op;
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            if (nums[i] == 0 && i != n - 1)
            {
                op.push_back(0);
            }

            op.push_back(nums[i++]);
        }
        int diff = op.size() - n;
        while (diff--)
        {
            op.pop_back();
        }
        nums = op;
    }
};