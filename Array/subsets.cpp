/*
78. Subsets
Medium

8348

133

Add to List

Share
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<vector<int>> op;

    void permut(vector<int> curr, vector<int> &nums, int i)
    {

        if (i > nums.size() || i < 0)
        {

            return;
        }

        if (i == nums.size())
        {
            op.insert(curr);
            return;
        }
        // not including nums[i] in subset
        permut(curr, nums, i + 1);
        // including nums[i] in subset
        curr.push_back(nums[i]);
        permut(curr, nums, i + 1);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> op2;
        vector<int> curr;

        permut(curr, nums, 0);
        for (auto e : op)
        {
            op2.push_back(e);
        }
        return op2;
    }
};
