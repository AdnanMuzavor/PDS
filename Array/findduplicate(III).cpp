#include<bits/stdc++.h>
using namespace std;

//QUESTION:
//Given an integer array nums and two integers k and t, return true if there are two distinct indices i and j in the array such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.

 
/*
Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false

*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
     vector<pair<int,int>> v(nums.size());
        for(int i=0;i<nums.size();i++){
            v[i].first=nums[i];
            v[i].second=i;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
              //  if((long long)v[i].first+t>=v[j].first){
                    if((long long)v[j].first-v[i].first<=t){
                    if(abs(v[i].second-v[j].second)<=k){
                        return true;
                    }
                }
                else{
                    break;
                }
            }
        }
        return false;
        }
};