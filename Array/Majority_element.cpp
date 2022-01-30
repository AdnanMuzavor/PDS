/*
169. Majority Element
Easy

7812

307

Add to List

Share
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> m;
        float n = nums.size();
        for (auto e : nums)
        {
            m[e]++;
        }
        for (auto e : m)
        {

            // cout<<ceil(n/2)<<endl;
            if (e.second >= ceil(n / 2))
                return e.first;
        }
        return -1;
    }
};