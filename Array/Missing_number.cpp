/*
268. Missing Number
Easy

4704

2775

Add to List

Share
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.



Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

*/
#include <bits/stdc++.h>
using namespace std;
// Brute force
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int i = nums.size();
        unordered_map<int, int> m;
        int j = 0;
        while (j <= i)
        {
            m[j]++;
            // cout<<"j "<<j<<"m[j]: "<<m[j]<<endl;
            j++;
        }
        for (auto e : nums)
        {
            m[e]--;
            // cout<<e<<" "<<m[e]<<endl;
        }
        for (auto e : m)
        {
            if (e.second >= 1)
                return e.first;
        }
        return -1;
    }
};
// Sorting approach
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        //         for(int i=0;i<nums.size();i++){
        //             if(nums[abs(nums[i])]<0){
        //                 nums[abs(nums[i])]=-nums[abs(nums[i])];
        //             }

        //         }
        //         for(int i=0;i<nums.size();i++){
        //             if(nums[i]>0){
        //                 return i;
        //             }
        //         }
        //         return -1;
        sort(nums.begin(), nums.end());
        int i = 0;
        if (nums[0] != 0)
            return 0;
        for (i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1] + 1)
                return nums[i - 1] + 1;
        }
        if (i == nums.size())
            return nums.size();
        return -1;
    }
};
// Efficient
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int result = nums.size();
        int i = 0;

        for (int num : nums)
        {
            result ^= num;
            result ^= i;
            i++;
        }

        return result;
    }
};