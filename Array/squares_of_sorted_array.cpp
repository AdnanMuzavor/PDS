/*
977. Squares of a Sorted Array
Easy

4463

144

Add to List

Share
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//BRUTE FORCE USING USING 2 POINTERS
    // vector<int> sortedSquares(vector<int>& A) {
    //     vector<int> res(A.size());
    //     int l = 0, r = A.size() - 1;
    //     for (int k = A.size() - 1; k >= 0; k--) {
    //        if(abs(A[r])>abs(A[l])){
    //            res[k]=A[r]*A[r];
    //            r--;
    //        }
    //         else{
    //             res[k]=A[l]*A[l];
    //             l++;
    //         }
    //     }
    //     return res;
    // }
    vector<int> sortedSquares(vector<int>& A) {
  vector<int> res(A.size());
  for (int pn = 0, pp = A.size() - 1, pos = A.size() - 1; pn <= pp; --pos)
    res[pos] = pow(abs(A[pn]) < abs(A[pp]) ? A[pp--] : A[pn++], 2);
  return res;
}  
};