/*
438. Find All Anagrams in a String
Medium

6855

248

Add to List

Share
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> op;
        int n1 = s.size();
        int n2 = p.size();
        // if s size is smaller thn p then it won't have anagram of p
        if (n1 < n2)
            return op;
        // Maintaing hash/record of appearance of each character of p
        vector<int> s1(26, 0); // hash for p
        vector<int> s2(26, 0); // hash for s
        for (int i = 0; i < n2; i++)
        {
            s1[p[i] - 'a'] += 1;
            s2[s[i] - 'a'] += 1;
        }
        // Using a sliding window
        // i will be starting point and j will be ending point
        int i = 0;
        int j = n2 - 1;
        while (j < n1)
        {
            // If vectors are same it indicates anagram is found
            if (s1 == s2)
            {
                op.push_back(i);
            }
            // Moving j to next char and adding it into record i.e in hash vector
            j++;
            if (j != n1)
            {
                s2[s[j] - 'a'] += 1;
            }
            // Since we moved j ahsead we'll be removing i i.e startimng point
            // so before moving to starting point removing ol starting point value
            s2[s[i] - 'a'] -= 1;
            i++;
        }
        return op;
    }
};