#include<bits/stdc++.h>
using namespace std;
/*
QUESTION:
 Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

 

Example 1:

Input: nums = [1,2,2,3,1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:

Input: nums = [1,2,2,3,1,4,2]
Output: 6
Explanation: 
The degree is 3 because the element 2 is repeated 3 times.
So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
*/
//Brute Force Approah
class Solution {
public:
    int l=INT_MAX;
    void checker(vector<int> nums,int i1,int j,int maxval,map<int,int> m){
        int size=(j-i1)+1;
       
        for(int i=i1;i<=j;i++){
            cout<<nums[i]<<" ";
            if(m[nums[i]]==maxval){
                if(size<l){
                
                    l=size;
               
                }
            }
         
        }
       cout<<endl;
        
    }
    int findShortestSubArray(vector<int>& nums) {
        //If all are unique degree will be 1
        set<int> ss(nums.begin(),nums.end());
        if(ss.size()==nums.size()) return 1;
        
        map<int,int> m;
        for(auto e:nums){
            m[e]++;
        }
        int ans=m[nums[0]];
        for(auto e:nums){
            if(m[e]>ans){
                ans=m[e];
            }
        }
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                checker(nums,i,j,ans,m);
            }
        }
        return l;
    }
};

//Optimised approach

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> start;//To keep track of first index where e was found
        map<int,int> end; //Top keep track of last index where e was found
        map<int,int> count;//To keep track of degree
            int i=0,maxval=INT_MIN,l=INT_MAX;
          
            for(auto e:nums){
                if(!count[e]) start[e]=i;
                if(!count[e]) end[e]=i;
                else if(count[e]) end[e]=i;
                count[e]++;
                if(count[e]>maxval){maxval=count[e];}
                i++;
            }
            for(auto e:nums){
                if(count[e]==maxval){
                    cout<<e<<" start: "<<start[e]<<" end: "<<end[e]<<endl;
                    if((end[e]-start[e])+1<l){
                        l=(end[e]-start[e])+1;
                    }
                }
            }
        return l;
    }
};