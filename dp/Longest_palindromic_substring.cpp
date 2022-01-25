/*
5. Longest Palindromic Substring
Medium

15528

908

Add to List

Share
Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
*/
#include <bits/stdc++.h>
using namespace std;
// DP based approach
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string sol = "";
        int n = s.size();
        if (n == 1)
            return s;
        if (n == 2 && s[0] == s[1])
            return s;
        if (n == 2 && s[0] != s[1])
        {
            sol += s[0];
            return sol;
        }
        int maxlen = 1, m = 0, n2 = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int start = 0;
        // we know that "a","b" stc are palindromes therefore dp[i][i]=1
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        // if arr[i]==arr[i+1] i.e "aa","bb", string is palindrome hence dp[i][i+1]=1
        for (int i = 0; i < n - 1; i++)
        {

            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                start = i;
                maxlen = 2;
            }
        }
        // first 2 cases already initialised
        for (int k = 3; k <= n; k++)
        {
            for (int i = 0; i < n - k + 1; i++)
            {
                int j = i + k - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                    if (k > maxlen)
                    {
                        start = i;
                        maxlen = k;
                    }
                }
            }
        }

        cout << maxlen << endl;
        int j = 0;
        while (j < maxlen)
        {
            sol += s[start++];
            j++;
        }

        return sol;
    }
};

// BRUTE FORCE APPROACH
class Solution
{
public:
    int l = INT_MIN;
    string sol = "";
    void palin(string s, int i, int j)
    {

        int c = 1;
        int m = i, n = j;
        while (i <= j)
        {

            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                c = 0;
                break;
            }
        }

        if (c == 1)
        {

            if ((n - m) + 1 > l)
            {
                l = n - m + 1;

                sol = "";
                for (int k = m; k <= n; k++)
                {

                    sol += s[k];
                }
            }
        }
    }
    string longestPalindrome(string s)
    {
        if (s.size() == 1)
            return s;
        if (s.size() == 2 && s[0] == s[1])
            return s;
        if (s.size() == 2 && s[0] != s[1])
        {
            sol += s[0];
            return sol;
        }
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < s.size(); j++)
            {
                palin(s, i, j);
            }
        }
        return sol;
    }
};