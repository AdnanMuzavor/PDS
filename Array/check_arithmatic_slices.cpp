/*
413. Arithmetic Slices
Medium

2542

221

Add to List

Share
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
Example 2:

Input: nums = [1]
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     bool canMakeArithmeticProgression(vector<int> arr, long long i, long long j)
    {

        long long d = 0;
        long long count = j - i + 1; // Number of elements
        if (count == 2)
            return false; // Only 2 elements hence AP
        if (count == 1 || count == 0)
            return false; // One element so no AP

        // Making temporary array of given slices/indices
        vector<int> temp(count, 0);
        int i2 = i, j2 = 0;
        while (i2 <= j)
        {
            temp[j2++] = arr[i2];
            i2++;
        }
        cout << "temp array: ";
        //sort(temp.begin(), temp.end());
        for (auto e : temp)
        {
            cout << e << " ";
        }
        cout << endl;
        // Checking if sub-array is arithmatic
        d = (long long)abs(temp[1] - temp[0]);
        cout << "d found is: " << d << endl;
        int i1 = 0;
        for (i1 = 1; i1 < temp.size() - 1; i1++)
        {

            if ((long long)abs(temp[i1 + 1] - temp[i1]) == d)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        cout << "i1: " << i1 << " tempsize: " << temp.size() - 1 << endl;
        // If arithmatic differnce till last element will be same
        if (i1 == temp.size() - 1)
            return true;
        // If non-arithmatic above case won't hold
        return false;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++)
        //         if(canMakeArithmeticProgression(nums,i,j)) count++;
        // }
        //Or just keep variable v and else part where v=0 if 'if' not satisfied
        vector<int> v(nums.size(),0);
        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                v[i]=1+v[i-1];
                count+=v[i];
            }
        }
        return count;
    }
};
