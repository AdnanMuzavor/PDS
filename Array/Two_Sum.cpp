/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        // Brute-Force
        /* vector<pair<int,int>> v;
         vector<int> op;
         for(int i=0;i<nums.size();i++){
             v.push_back({nums[i],i});
         }
         map<pair<int,int>,int> m;
         for(auto e:v){
             m[e]++;
         }
        for(int i=0;i<nums.size();i++){
            int val=target-nums[i];
            for(int j=0;j<nums.size();j++){
                if(m[{val,j}] && i!=j){
                    op.push_back(j);
                    op.push_back(i);
                    return op;
                }
            }
        }
         op.push_back(-1);
         op.push_back(-1);
         return op;
         */

        // Optimised approach
        map<int, int> m;
        vector<int> op;
        int i = 0;
        for (auto e : nums)
        {
            m[e] = i;
            i++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int val = target - nums[i];
            if (m[val] && m[val] != i)
            {
                op.push_back(m[val]);
                op.push_back(i);
                return op;
            }
        }
        return op;
    }
};