/*
377. Combination Sum IV
Medium

3102

356

Add to List

Share
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.



Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0
*/
#include <bits/stdc++.h>
using namespace std;
//BRUTE FORCE
class Solution
{
public:
    set<vector<int>> op;
    void permute(vector<int> nums, vector<int> curr, int target, int &c, int index)
    {
        if (target == 0)
        {
            op.insert(curr);
            c++;
        }
        if (index >= nums.size())
        {

            return;
        }

        for (int i = 0; i < nums.size() && nums[i] <= target; i++)
        {
            curr.push_back(nums[i]);
            permute(nums, curr, target - nums[i], c, i);
            curr.pop_back();
        }
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        int count = 0;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        permute(nums, curr, target, count, 0);
        return op.size();
    }
};