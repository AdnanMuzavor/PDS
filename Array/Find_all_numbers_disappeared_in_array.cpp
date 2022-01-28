/*
48. Find All Numbers Disappeared in an Array
Easy

5953

359

Add to List

Share
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.



Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        // BRUTE FORCWE
        //          int n=nums.size();
        //  vector<int> op;
        //  unordered_map<int,int> m;
        //  int j=1;
        //  while(j<=n){
        //      m[j]++;
        //      j++;
        //  }
        //  for(auto e:nums){
        //      m[e]--;
        //  }
        //  for(auto e:m){
        //      if(e.second>=1) op.push_back(e.first);
        //  }
        //  return op;

        // HNegsative indexing
        int n = nums.size();
        vector<int> op;
        for (int i = 0; i < n; i++)
        {
            if (nums[abs(nums[i]) - 1] > 0)
            {
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                // cout<<i+1<<endl;
                op.push_back(i + 1);
            }
        }
        return op;
    }
};