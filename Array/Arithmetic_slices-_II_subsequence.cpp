/*
446. Arithmetic Slices II - Subsequence
Hard

1255

84

Add to List

Share
Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
The test cases are generated so that the answer fits in 32-bit integer.

 

Example 1:

Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
Example 2:

Input: nums = [7,7,7,7,7]
Output: 16
Explanation: Any subsequence of this array is arithmetic.
*/

#include <bits/stdc++.h>
using namespace std;
// BRUTE FORCE

class Solution {
public:
    
  // O(N*2^N)
    void permute(vector<int> curr,vector<int> nums,int start,int &ans){
        //If current vector size is >=3
        if(curr.size()>=3){
            int i=2;
            //We process this current to check if arithmetic sequence is there
            for(i=2;i<curr.size();i++){
              
               if((long long)curr[i]-curr[i-1]!=(long long)curr[i-1]-curr[i-2]) break;
            }
            //If arithmatic i will reach at last so ans++
            if(i==curr.size()) {
                ans++;
              
            }
        }
       //If start exceeds size we return;
       if(start>=nums.size()) return;
       //Iterating by taking next elements
       for(int i=start;i<nums.size();i++){
           curr.push_back(nums[i]);
           permute(curr,nums,i+1,ans);
           curr.pop_back();
       }                 
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int>  curr;
        int ans=0;
        permute(curr,nums,0,ans);
        return ans;
    }
};