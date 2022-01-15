/*
541. Reverse String II
Easy

813

2125

Add to List

Share
Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.



Example 1:

Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Example 2:

Input: s = "abcd", k = 2
Output: "bacd"
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int min(int a, int b)
    {
        if (a < b)
            return a;
        return b;
    }
    string reverse(string s, int i, int j)
    {
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
    string reverseStr(string s, int k)
    {
        int i = 0, j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            j = min(i + k - 1, s.size() - 1);
            s = reverse(s, i, j);
            cout << s << endl;
            if (j == s.size() - 1)
            {
                break;
            }
            i = j + k;
        }

        return s;
    }
};