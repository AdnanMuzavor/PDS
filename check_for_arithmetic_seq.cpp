/*
A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

 

Example 1:

Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
Example 2:

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        long long d=0;
        int n=arr.size();
        int i=0;
        if(n==0 || n==1) return false;
        if(n==2) return true;
        d=(long long)abs(arr[1]-arr[0]);
        for( i=1;i<arr.size()-1;i++){
          if((long long)abs(arr[i+1]-arr[i])==d){
              continue;
          }
            else{
                break;
            }
        }
       if(i==n-1) return true;
        return false;
    }
};

