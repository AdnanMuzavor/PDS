/*
383. Ransom Note
Easy

1437

279

Add to List

Share
Given two stings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.



Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string r, string m)
    {
        // Single map approach
        int n1 = r.size();
        int n2 = m.size();
        if (n1 == 1 && n2 == 1 && r[0] == m[0])
        {
            return true;
        }
        else if (n1 == 1 && n2 == 1 && r[0] != m[0])
        {
            return false;
        }
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for (int i = 0; i < n1; i++)
        {
            m1[r[i]]++;
        }
        for (int i = 0; i < n2; i++)
        {
            m2[m[i]]++;
        }
        for (int i = 0; i < n1; i++)
        {
            if (m2[r[i]] == 0 || !m2[r[i]])
            {
                return false;
            }
            if (m2[r[i]] && m2[r[i]] < m1[r[i]])
            {
                return false;
            }
        }

        return true;

        // Single map approach
        unordered_map<char, int> m1;
        for (int i = 0; i < n1; i++)
        {
            m1[r[i]]++;
        }
        for (int i = 0; i < n2; i++)
        {
            m1[m[i]]--;
        }
        for (int i = 0; i < n1; i++)
        {
            if (m1[r[i]] >= 1)
            {
                return false;
            }
        }
        return true;
    }
};