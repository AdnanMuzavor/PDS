/*
409. Longest Palindrome
Easy

2372

142

Add to List

Share
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.



Example 1:

Input: s = "abccccdd"
Output: 7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Example 3:

Input: s = "bb"
Output: 2
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        if (s.size() == 1)
            return 1;
        if (s.size() == 2)
        {
            if (s[0] == s[1])
                return 2;
        }
        int ans = 0, flag = 0;
        char c;
        unordered_map<char, int> m;
        for (auto e : s)
            m[e]++;
        // Taking all those whose occurence is even;
        for (auto e : m)
        {
            if (e.second % 2 == 0)
            {
                ans += e.second;
            }
            // Taking only one from those who occur only once
            // Flag helps in taking it only once
            else if (e.second == 1 && flag == 0)
            {
                flag = 1;
                ans += 1;
                c = e.first;
            }
            // Taking care of case like "ccc"
            else if (e.second % 2 != 0 && flag == 0)
            {
                flag = 1;
                ans += e.second;
                // Saving this character so that we dont't take it again next loop
                c = e.first;
            }
        }
        // Now for all those whose occurence is odd,we'll be taking even occcurences
        for (auto e : m)
        {
            if (e.second % 2 != 0 && e.first != c)
            {
                ans += (e.second - 1);
            }
        }
        return ans;
    }
};