/*
451. Sort Characters By Frequency
Medium

3781

177

Add to List

Share
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.



Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        // Map-1 maps frequency of char with occurence from a-b order
        map<char, int> m;
        // Crreates string of char whicjn occurs frequncy no of times
        map<int, string> m2;
        // Mapping chars with frequency
        for (auto e : s)
        {
            m[e]++;
        }
        // Creating string and mapping with occurences
        for (auto e : m)
        {
            int a = e.second;
            while (a--)
            {
                m2[e.second] += e.first;
            }
        }
        // Vector to keep track of various occurences
        vector<int> occur;
        for (auto e : m2)
        {
            occur.push_back(e.first);
        }
        // Since max occurence is at last string from last
        // and appending that string into ans
        string res = "";
        for (int i = occur.size() - 1; i >= 0; i--)
        {
            res += m2[occur[i]];
        }
        return res;
    }
};