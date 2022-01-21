/*
287. Find the Duplicate Number
Medium

11128

1170

Add to List

Share
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Brute Force Approach
        //int n=nums.size();
        // for(int i=0;i<n;i++){
        //     int m=nums[i];
        //         int j=i+1;
        //           while(j<n){
        //               if(nums[j]==m){
        //                   return m;
        //               }
        //               j++;
        //           }
        // }

        
        //Better approach(O(n) space)
        // int n=nums.size();
        // unordered_map<int,int> m;
        // for(int i=0;i<n;i++){
        //         if(!m[nums[i]]){
        //             m[nums[i]]++;
        //         }
        //         else{
        //             return nums[i];
        //         }
        // }


        // return -1;

             //More Better approach(O(1) space)
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]>0){
                nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
            }
            else{
                return abs(nums[i]);
            }
        }
        return -1;
    }
};