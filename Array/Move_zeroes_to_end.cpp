/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.



Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        //APPROACH-1 o(N) AND O(N)
        // vector<int> v;
        // for(auto e:nums){
        //     if(e!=0){
        //         v.push_back(e);
        //     }
        // }
        // int n=v.size();
        // for(int i=0;i<nums.size();i++){
        //     if(i<n){
        //         nums[i]=v[i];
        //     }
        //     else{
        //         nums[i]=0;
        //     }
        // }
        
        //USING VECTOR PROPERTY
//         int count=0;
//         for(auto e:nums){
//             if(e==0){
//                 nums.erase(find(nums.begin(),nums.end(),0));
//                 nums.push_back(0);
//             }
//         }
        
        //Using pointer pointing at index0
        int nonzero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[nonzero]=nums[i];
                nonzero++;
            }
        }
        for(int i=nonzero;i<nums.size();i++){
            nums[i]=0;
        }
    }
};