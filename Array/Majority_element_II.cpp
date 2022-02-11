/*
229. Majority Element II
Medium

4226

266

Add to List

Share
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.



Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> op;
        int n = nums.size();
        // METHOD-I
        //         unordered_map<int,int> m;
        //         for(auto e:nums) m[e]++;
        //         for(auto e:m){
        //             if(e.second>(n/3)) op.push_back(e.first);

        //         }
        //        return op;
        // METHOD-II NO EXTRA SPACE
        sort(nums.begin(), nums.end());
        int ele = nums[0], c = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == ele)
            {
                c++;
            }
            else
            {
                if (c > (n / 3))
                    op.push_back(ele);
                ele = nums[i];
                c = 1;
            }
        }
        if (c > n / 3)
        {
            op.push_back(ele);
        }
        return op;
    }
};