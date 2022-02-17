/*
205. Isomorphic Strings
Easy

3226

618

Add to List

Share
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.



Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> m;
        unordered_map<char, char> m2;
        int i = 0;
        for (auto e : s)
        {
            // If within bound
            if (i < t.size())
            {
                // If current char is not mapped with char in other string we mapped it
                if (!m[e] && !m2[t[i]])
                {
                    m[e] = t[i];
                    m2[t[i]] = e;
                }
                // Else if elememt is mapped
                // Then we check if it's mapped with same char
                // If different character we return false
                else if ((m[e] && m[e] != t[i]) || (m2[t[i]] && m2[t[i]] != e))
                {

                    return false;
                }
            }
            i++;
        }
        return true;
    }
};