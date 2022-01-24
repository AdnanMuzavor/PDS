/*
46. Permutations
Medium

8821

169

Add to List

Share
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void perm(vector<int> v, int begin, vector<vector<int>> &op)
    {
        if (begin >= v.size())
        {
            op.push_back(v);
            return;
        }
        for (int i = begin; i < v.size(); i++)
        {
            swap(v[begin], v[i]);
            perm(v, begin + 1, op);
            swap(v[i], v[begin]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> op;
        if (nums.size() == 1)
        {
            op.push_back(nums);
            return op;
        }
        perm(nums, 0, op);
        return op;
    }
};