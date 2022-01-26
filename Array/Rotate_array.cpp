/*
Given an array, rotate the array to the right by k steps, where k is non-negative.



Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach-1 related
    //  void rotate2(vector<int> &v){
    //      int x=v[v.size()-1];
    //      // int x=0;
    //       for(int i=v.size()-1;i>=1;i--){
    //           v[i]=v[i-1];
    //       }
    //       v[0]=x;
    //  }
    // Approach-3 related
    void reverse(vector<int> &v, int l, int h)
    {
        while (l < h)
        {
            swap(v[l], v[h]);
            l++;
            h--;
        }
    }
    void rotate(vector<int> &nums, int k)
    {

        // Brute Force Approach
        //    if(k==0) return;
        //    if(k%nums.size()==0) return;
        //  while(k--){
        //      rotate2(nums);
        //  }

        // Aproach 2(pop from back insert at front)
        //  while(k--){
        //      int last=nums[nums.size()-1];
        //      nums.pop_back();
        //    //  cout<<last<<endl;
        //      nums.insert(nums.begin(),last);
        //  }

        // Appraoch 3
        // Reverse 0 to n-k-1
        // Reverse n-k to n-1
        // Reverse 0 to n-1
        int n = nums.size();
        k = k % n;
        //Inbuilt reverse(more efficient)
        // reverse(nums.begin(), nums.begin() + (n - k - 1) + 1);
        // reverse(nums.begin() + n - k, nums.end());
        // reverse(nums.begin(), nums.end());

        // Userdefiend methods(less efficient)
        //  reverse(nums,0,n-k-1);
        //  reverse(nums,n-k,n-1);
        //  reverse(nums,0,n-1);
    }
};
