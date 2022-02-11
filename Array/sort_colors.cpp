/*
75. Sort Colors
Medium

8671

382

Add to List

Share
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
*/
#include <bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // direct
        sort(nums.begin(), nums.end());
        // indirect
        int c1 = 0, c2 = 0, c = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                c++;
            else if (nums[i] == 1)
                c1++;
            else
                c2++;
        }
        for (int i = 0; i < c; i++)
        {
            nums[i] = 0;
        }
        for (int i = c; i < c + c1; i++)
        {
            nums[i] = 1;
        }
        for (int i = c + c1; i < c + c1 + c2; i++)
        {
            nums[i] = 2;
        }
    }
};
// TO POIN TER APPROACH
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
      
        int l = 0, m = 0, h = nums.size() - 1;
        while (m <= h)
        {
            if (nums[m] == 0)
            {
                swap(nums[m++], nums[l++]);
            }
            else if (nums[m] == 2)
            {
                swap(nums[m], nums[h--]);
            }
            else
            {
                m++;
            }
        }
    }
};