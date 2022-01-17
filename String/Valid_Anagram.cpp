/*
242. Valid Anagram
Easy

3899

196

Add to List

Share
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int n1 = s.size();
        int n2 = t.size();
        if (n1 != n2)
            return false;
        // 2 map approach
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for (int i = 0; i < n1; i++)
        {
            m1[s[i]]++;
        }
        for (int i = 0; i < n2; i++)
        {
            m2[t[i]]++;
        }
        for (int i = 0; i < n1; i++)
        {
            if (m1[s[i]] != m2[s[i]])
            {
                return false;
            }
        }
        return true;

        // 1 map approach
        unordered_map<char, int> m1;

        for (int i = 0; i < n1; i++)
        {
            m1[s[i]]++;
        }
        for (int i = 0; i < n2; i++)
        {
            m1[t[i]]--;
        }
        for (int i = 0; i < n1; i++)
        {
            if (m1[s[i]] >= 1)
            {
                return false;
            }
        }
    }
};