/*
136. Single Number
Easy

8357

289

Add to List

Share
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.



Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
*/
#include <bits/stdc++.h>
using namespace std;

// Brute force without bit manipulation
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        //Array will be of length 1 or >=3

        //When array  of l=1
        if (n == 1)
            return nums[0];
        //When array of l>=3 and unique element is at beginning
        if (nums[1] == nums[2])
            return nums[0];
         //When array of l>=3 and unique element is at end   
        if (nums[n - 2] == nums[n - 3])
            return nums[n - 1];
        //Middle element cases    
        for (int i = 1; i < nums.size() - 1; i++)
        {
            //A unique element will neither be equal to element on left nor on right
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
                return nums[i];
        }
        return -1;
        
        //Bit manipulation
   int result=nums[0];
        for(int i=1;i<nums.size();i++){
            result=result^nums[i];
        }
        return result;

    }
};