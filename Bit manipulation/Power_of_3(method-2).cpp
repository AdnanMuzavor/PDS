/*
326. Power of Three
Easy

693

91

Add to List

Share
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.



Example 1:

Input: n = 27
Output: true
Example 2:

Input: n = 0
Output: false
Example 3:

Input: n = 9
Output: true
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {

        if (n < 1)
            return false;
        while (n % 3 == 0)
        {
            n = n / 3;
        }
        return n == 1;
    }
};
