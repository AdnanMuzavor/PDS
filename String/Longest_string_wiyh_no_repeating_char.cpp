/*
3. Longest Substring Without Repeating Characters
Medium

20433

926

Add to List

Share
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <bits/stdc++.h>
using namespace std;

//O(2n) approach
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        if (s.size() == 0)
            return 0;
        if (s.size() == 1)
            return 1;
        int l = 0, r = 0;
        int length = INT_MIN;
        unordered_set<char> s1;
        while (r < s.length())
        {
            if (s1.find(s[r]) == s1.end())
            {
                s1.insert(s[r]);
                length = max(length, r - l + 1);
                r++;
            }
            else
            {

                s1.erase(s[l]);
                l++;
                length = max(length, r - l + 1);
            }
        }
        return length;
    }
};
