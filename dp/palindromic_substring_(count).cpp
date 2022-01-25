/*
647. Palindromic Substrings
Medium

5681

151

Add to List

Share
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.



Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSubstrings(string s)
    {
        int c = 0;
        int n = s.size();
        if (n == 1)
            return 1;
        if (n == 2 && s[0] == s[1])
            return 3;
        if (n == 2 && s[0] != s[1])
            return 2;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
            c++;
        }
        cout << c << endl;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                c++;
            }
        }
        cout << c << endl;
        for (int k = 3; k <= n; k++)
        {
            for (int i = 0; i < n - k + 1; i++)
            {
                int j = i + k - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                    c++;
                }
            }
        }
        return c;
    }
};