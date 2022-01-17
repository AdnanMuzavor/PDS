/*
567. Permutation in String
Medium

4095

115

Add to List

Share
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.



Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*/
#include <bits/stdc++.h>
using namespace std;

// EFFICIENT APPROACH
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        // Getting lengths
        int n1 = s1.length();
        int n2 = s2.length();
        if (n2 < n1)
            return false;

        // Maintaining hash for each character
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        // Hashing first few chars of both strings
        for (int i = 0; i < s1.size(); i++)
        {
            v1[s1[i] - 'a'] += 1;
            v2[s2[i] - 'a'] += 1;
        }
        int i = 0;
        int j = s1.size() - 1;
        while (j < s2.size())
        {
            if (v1 == v2)
            {
                return true;
            }
            j++;
            if (j != s2.size())
            {
                v2[s2[j] - 'a'] += 1;
            }
            v2[s2[i] - 'a'] -= 1;
            i++;
        }
        return false;
    }
};
// BRUTE FORCE APPROACH
class Solution
{
public:
    bool substring(string s1, int l, int h, map<char, int> m)
    {
        for (int i = l; i <= h; i++)
        {
            if (m[s1[i]] != 0)
            {
                m[s1[i]]--;
            }
        }
        for (auto e : m)
        {
            if (e.second >= 1)
            {
                return false;
            }
        }

        return true;
    }
    bool checkInclusion(string s1, string s2)
    {

        int n1 = s1.size();
        map<char, int> m;
        for (int i = 0; i < n1; i++)
        {
            m[s1[i]]++;
        }

        int i = 0, j = s1.size() - 1;

        while (j < s2.size())
        {
            if (substring(s2, i, j, m) == 1)
            {
                return true;
            }
            else
            {
                i++;
                j++;
            }
        }
        return false;
    }
};