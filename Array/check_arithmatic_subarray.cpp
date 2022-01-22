/*
A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic:

1, 1, 2, 5, 7
You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.

Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, and false otherwise.



Example 1:

Input: nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
Output: [true,false,true]
Explanation:
In the 0th query, the subarray is [4,6,5]. This can be rearranged as [6,5,4], which is an arithmetic sequence.
In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged as an arithmetic sequence.
In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged as [3,5,7,9], which is an arithmetic sequence.
Example 2:

Input: nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
Output: [false,true,false,false,true,true]

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> arr, long long i, long long j)
    {

        long long d = 0;
        long long count = j - i + 1; // Number of elements
        if (count == 2)
            return true; // Only 2 elements hence AP
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
        sort(temp.begin(), temp.end());
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
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> op;
        int n = l.size();
        for (int i = 0; i < n; i++)
        {
            op.push_back(canMakeArithmeticProgression(nums, (long long)l[i], (long long)r[i]));
        }
        return op;
    }
};

//An optimised and clean approach
class Solution 
{
public:
    // function to check wheather an array can form an arithmetic sequence or not
    bool isArithmetic(vector<int>&arr) {
        
        // sort the array
        sort(arr.begin(),arr.end());
        
        // check the condition for arithmetic sequence
        for(int i=0;i<arr.size()-2;i++) {
            if(arr[i+1]-arr[i]!=arr[i+2]-arr[i+1]) {
                return false;
            }
        }
        return true;
    }
    vector<bool>checkArithmeticSubarrays(vector<int>&nums,vector<int>&l,vector<int>&r) 
    {
        // 'ans' will be our answer
        vector<bool>ans(l.size());
        
        // iterate over the queries and populate the 'ans' vector
        for(int i=0;i<l.size();i++) {
            // if the size of the subarray is less than 2 then it can't be an arithmetic sequence
            if(r[i]-l[i]+1<2) {
                ans[i]=false;
            }
            else {
                // store the subarray elements in a temporary array
                vector<int>tmp(r[i]-l[i]+1);
                copy(nums.begin()+l[i],nums.begin()+r[i]+1,tmp.begin());
                
                // call the function and store the result
                ans[i]=isArithmetic(tmp);
            }
        }
        
        // finally return the answer
        return ans;
    }
};