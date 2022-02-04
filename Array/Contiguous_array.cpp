/*
525. Contiguous Array
Medium

4440

186

Add to List

Share
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.



Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // //SECOND BTRUTE FORCE
    // int findMaxLength(vector<int>& nums) {
    //     if(nums.size()==1) return 0;
    //     int start=0,z=0,l=0;
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i]==0)z++;
    //         else z--;
    //         if(z==0) l=max(l,i-start+1);
    //         if(i==nums.size()-1){
    //             start++;
    //             i=start;
    //            // cout<<"shifted strt to : "<<start<<endl;
    //             if(nums[start]==0)z=1;
    //             else z=-1;
    //         }
    //        // if(i-start+1 <l) break;
    //     }
    //     return l;
    // }

    // //BRUTE FORCE APPROACH
    //    class Solution {
    // public:
    //     int l=0;
    //     void check(vector<int>& nums,int i,int j){
    //         if(i==j) return;
    //         int z=0;
    //         for(int k=i;k<=j;k++){
    //             if(nums[k]==0) z++;
    //             else if(nums[k]==1) z--;
    //         }
    //         if(z==0){
    //             l=max(l,j-i+1);
    //         }
    //     }
    //     int findMaxLength(vector<int>& nums) {
    //         if(nums.size()==1) return 0;
    //         for(int i=0;i<nums.size();i++){
    //             for(int j=0;j<nums.size();j++){
    //                 if(i!=j){
    //                  //   cout<<"pasing: "<<i<<" "<<j<<endl;
    //                 check(nums,i,j);
    //                 }
    //             }
    //         }

    //         return l;
    //     }
    // };

    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size(), s = 0, l = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            // If it's 1 add into sum ,if it's zero subtract 1 from sum
            if (nums[i] == 0)
                s = s - 1;
            else
                s = s + 1;
            // If sum approaches zero means we have sequqnece with equal no of 0s and 1s
            // from the beginning therefore we subtract current index i from first index 0
            if (s == 0)
            {
                l = max(l, i - 0 + 1);
            }
            // If sum was occured in map i.e previsoly occured sum ,
            // it indicates that there is someherre zero sum in between
            // due to which we got same sum we got before
            else if (m.find(s) != m.end())
            {
                l = max(l, i - m[s]);
            }
            // else we insert element into the map
            else
            {
                m[s] = i;
            }
        }
        return l;
    }
};