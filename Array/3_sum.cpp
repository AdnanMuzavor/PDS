/*
15. 3Sum
Medium

15786

1513

Add to List

Share
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> op;
        vector<int> v;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int l = i + 1, h = nums.size() - 1;
            int newtarget = 0 - nums[i];
            while (l < h)
            {
                int sum = nums[l] + nums[h];
                if (sum == newtarget)
                {
                    v.push_back(nums[i]);
                    v.push_back(nums[l]);
                    v.push_back(nums[h]);
                    op.push_back(v);
                    v.clear();
                    int x = nums[l], y = nums[h];
                    while (l < h && nums[l] == x)
                        l++;
                    while (h > l && nums[h] == y)
                        h--;
                }
                else if (sum < newtarget)
                    l++;
                else
                    h--;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return op;
    }
};