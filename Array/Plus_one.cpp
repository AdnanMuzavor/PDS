/*
66. Plus One
Easy

3746

3979

Add to List

Share
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.



Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        int lastval = digits[n - 1];
        // If last val is not 9, we can simply add one return same array
        if (lastval < 9)
        {
            digits[n - 1] = lastval + 1;
            return digits;
        }
        else
        {
            // Else we can first take last val,add one and push it
            // And continur from second last element to deal with 9+1 case
            // We can return final op and retun it
            vector<int> op;
            op.push_back(0);
            int c = 1;
            for (int i = n - 2; i >= 0; i--)
            {
                int sum = digits[i] + c;
                c = sum / 10;
                op.push_back(sum % 10);
            }
            if (c == 1)
                op.push_back(1);
            reverse(op.begin(), op.end());
            return op;
        }
    }
};