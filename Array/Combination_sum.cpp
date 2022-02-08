/*
39. Combination Sum
Medium

8970

207

Add to List

Share
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.



Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // BRUTE FORCE
    set<vector<int>> op;
    void permute(vector<int> curr, int target, vector<int> &candidates, int sum)
    {
        if (sum == target)
        {
            sort(curr.begin(), curr.end());
            op.insert(curr);
            return;
        }
        if (sum > target)
            return;
        for (int i = 0; i < candidates.size(); i++)
        {
            curr.push_back(candidates[i]);
            permute(curr, target, candidates, sum + candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> curr;
        permute(curr, target, candidates, 0);
        vector<vector<int>> op1;
        for (auto e : op)
        {
            op1.push_back(e);
        }

        return op1;
    }
};