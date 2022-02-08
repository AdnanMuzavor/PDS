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
//STRIVER SOLN CODED IN OPTIMISED WAY
class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};
//STRIVER SOLUTION
class Solution {
public:
   void permute( vector<vector<int>> &op1,vector<int> curr,int target,int start,vector<int> nums){
       //If we reachb at last index in array we should stop
       if(start==nums.size()){
           //If target ==0 means required combination in curr has value we required
           if(target==0){
               op1.push_back(curr);
           }
           return;
       }
       //if nums[start] index has value<target thn only we'll be able to take current
       //index value and continue ahead withn next
       //I.e we take an index multiple times only and only if it's lesser thn current target
       //If it exceeds it'll be retirn and next line will run

       //Deciding to take this element once again
       if(nums[start]<=target){
           curr.push_back(nums[start]);
           permute(op1,curr,target-nums[start],start,nums);
           curr.pop_back();
       }
       //not taking this element instead moving ahead with next
        permute(op1,curr,target,start+1,nums);
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> op1;
        permute(op1,curr,target,0,candidates);
        
        // for(auto e:op){
        //     op1.push_back(e);
        // }
        
        return op1;
    }
};
// BETTTER BRUTE FORCE
set<vector<int>> op;
void permute(vector<int> curr, int target, vector<int> &candidates, int sum)
{
    // Sorting is done with an aim to remove to prevent duplicate
    if (sum == target)
    {
        sort(curr.begin(), curr.end());
        op.insert(curr);
        return;
    }
    // If sum>target there is no use of processing it
    if (sum > target)
        return;
    for (int i = 0; i < candidates.size(); i++)
    {
        curr.push_back(candidates[i]);
        // If addition of curr value in o/p array makes o/p array
        // value equal to targetb or not equal thn still lesser
        // It it's greater we shall not take it and go ahead with fn calling
        if (sum + candidates[i] <= target)
        {
            permute(curr, target, candidates, sum + candidates[i]);
        }
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