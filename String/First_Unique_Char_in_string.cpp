/*
387. First Unique Character in a String
Easy

4274

177

Add to List

Share
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.



Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
*/
#include <bits/stdc++.h>
using namespace std;

// 2 maps approach
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int n = s.size();

        map<char, int> m1;
        map<char, int> m2;
        for (int i = 0; i < n; i++)
        {
            m1[s[i]]++;
            m2[s[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            if (m1[s[i]] == 1)
            {
                return m2[s[i]];
            }
        }

        return -1;
    }
};

// 1 map approach
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int n = s.size();

        map<char, int> m1;
        //  map<char,int> m2;
        for (int i = 0; i < n; i++)
        {
            if (!m1[s[i]])
            {
                m1[s[i]] = i + 1;
            }
            else
            {
                m1[s[i]] = -1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (m1[s[i]] != -1)
            {
                return m1[s[i]] - 1;
            }
        }

        return -1;
    }
};