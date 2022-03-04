/*
338. Counting Bits
Easy

5798

287

Add to List

Share
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.



Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
*/
#include <bits/stdc++.h>
using namespace std;
// BRUTE FORCE:

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> op;
        //Base case for zero
        op.push_back(0);
        if (n == 0)
            return op;
        //Base case for one    
        op.push_back(1);
        if (n == 1)
            return op;
        //Remaining elements    
        for (int i = 2; i <= n; i++)
        {
            int c = 0;
            int number = i;
            while (number > 0)
            {
                int val = number % 2;
                number = number / 2;
                if (val == 1)
                    c++;
            }
            op.push_back(c);
        }
        return op;
    }
};