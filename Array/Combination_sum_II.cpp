/*
40. Combination Sum II
Medium

4489

123

Add to List

Share
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]
*/
#include <bits/stdc++.h>
using namespace std;
// OPTIMISED SOLUTION
class Solution
{
public:
    // Recursive function permute
    void permute(vector<vector<int>> &op, vector<int> curr, vector<int> &nums, int start, int target)
    {
        // If target zero means we found all elemets which sum up to target
        if (target == 0)
        {
            op.push_back(curr);
            return;
        }
        // Sterting from given satrting index as it'll help in preventomg multiple calls
        for (int i = start; i < nums.size(); i++)
        {
            // If nums[i] is > target means all next elemets will also be > target since we are               //sorting the array hence we break the loop as it's obvious that other elemet after             //nums[i] will give result
            if (nums[i] > target)
                return;
            // To avoid similar /same elements as they'll reesult in same combination
            if (i >= 1 && nums[i] == nums[i - 1] && i - 1 >= start)
                continue;
            // Pushing eleemt into current i.e considering it since it is <=target and can give             //target
            curr.push_back(nums[i]);
            // since nums[i] included target becomes target-nums[i]
            permute(op, curr, nums, i + 1, target - nums[i]);
            // i+1 one is passed because i is considered and we cannot take up duplicates
            curr.pop_back();
            // popping back to try next combo if current does'nt works
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &nums, int target)
    {
        // Sorting array so that we can get the numbers in order
        sort(nums.begin(), nums.end());
        vector<vector<int>> op;
        // Vcetor to be used temporarily
        vector<int> curr;
        // Recursive fn
        // It'll take
        //->final output op
        //->temp array i.e curr
        //->index from where in shouyld start
        //->target i.e curr target i.e target after taking a element
        //->nums array
        permute(op, curr, nums, 0, target);
        return op;
    }
};
// BRUTE FORCE


class Solution
{
public:
    // set<vector<int>> op;
    vector<vector<int>> op;
    void permute(vector<int> curr, int currtarget, int startindex, vector<int> nums)
    {
        if (currtarget == 0)
        {
            // op.insert(curr);
            op.push_back(curr);
            return;
        }
        for (int i = startindex; i < nums.size() && currtarget >= nums[i]; i++)
        {
            curr.push_back(nums[i]);
            permute(curr, currtarget - nums[i], i + 1, nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        permute(curr, target, 0, candidates);
        //  vector<vector<int>> op1;
        // for(auto e:op) op1.push_back(e);
        //   return op1;
        return op;
    }
};