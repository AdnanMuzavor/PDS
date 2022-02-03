/*
90. Subsets II
Medium

4282

137

Add to List

Share
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

#include <bits/stdc++.h>
using namespace std;

// BRUTE force ->sorting array to get same subsets
// Since we are adding first in set duplicate ones will be discarded
class Solution
{
public:
    set<vector<int>> op;
    void countreps(vector<int> currs)
    {
    }
    void permut(vector<int> curr, vector<int> &nums, int i)
    {
        if (i > nums.size())
            return;
        // If all elements are traversed i will be equal to nums.size()
        if (i == nums.size())
        {

            op.insert(curr);

            return;
        }
        // Excluding current element
        permut(curr, nums, i + 1);
        if (i + 2 < nums.size() && nums[i + 2] == nums[i + 1])
            permut(curr, nums, i + 2);
        // Including the current element
        curr.push_back(nums[i]);
        permut(curr, nums, i + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> curr;
        vector<vector<int>> op2;
        sort(nums.begin(), nums.end());
        permut(curr, nums, 0);
        for (auto e : op)
        {
            op2.push_back(e);
        }
        return op2;
    }
};
// EFFICIUENT SOLN

class Solution
{
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        std::vector<int> vec;
        subsetsWithDup(res, nums, vec, 0);
        return res;
    }

private:
    void subsetsWithDup(std::vector<std::vector<int>> &res, std::vector<int> &nums, std::vector<int> &vec, int begin)
    {
        res.push_back(vec);
        for (int i = begin; i != nums.size(); ++i)
            if (i == begin || nums[i] != nums[i - 1])
            {
                vec.push_back(nums[i]);
                subsetsWithDup(res, nums, vec, i + 1);
                vec.pop_back();
            }
    }
};