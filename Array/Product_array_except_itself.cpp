/*
238. Product of Array Except Self
Medium

10885

677

Add to List

Share
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.



Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> op(nums.size(), 0);
        int cz = -1; // index with val=0
        int i = 0, p = 1;
        for (auto e : nums)
        {
            // If only one index with val=0
            // Kepp track of that index
            if (e == 0 && cz == -1)
            {
                cz = i;
            }
            // If morfe thn 2 zeros means entire o/p array =0
            else if (e == 0 && cz != -1)
            {
                cz = 10;
            }
            i++;
        }

        // If more thn 1 zero means entire array is zero
        if (cz == 10)
        {
            return op;
        }

        // Calculating product leaving the index with val=0 i.e cz
        i = 0;
        for (auto e : nums)
        {
            if (i != cz)
            {
                p = p * e;
            }
            i++;
        }
        cout << "product: " << p << endl;
        // If only one zero thn making val at that index as non-zero product
        // and rest will be zero
        if (cz != -1)
        {
            op[cz] = p;
            return op;
        }
        // No zero case
        else
        {

            i = 0;
            // Product at index will be total-product/element-at-that-index
            for (auto e : nums)
            {

                op[i] = p / e;
                i++;
            }
        }
        return op;
    }
};