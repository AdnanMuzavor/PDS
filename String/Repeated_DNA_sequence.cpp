/*
187. Repeated DNA Sequences
Medium

1784

392

Add to List

Share
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.



Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
*/
#include <bits/stdc++.h>
using namespace std;

// SOLUTION->LESS OPTIMISED
class Solution
{
public:
    string getstring(int i, int j, string s)
    {
        string res = "";
        while (i <= j)
        {
            res += s[i];
            i++;
        }
        return res;
    }
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> v1;
        if (s.size() <= 10)
            return v1;
        unordered_map<string, int> m;
        if (s.size() == 10)
        {
            v1.push_back(s);
            return v1;
        }
        int i = 0;
        for (int j = 9; j < s.size(); j++)
        {
            //  cout<<i<<" "<<j<<endl;
            string curr = getstring(i, j, s);
            // cout<<curr<<endl;
            if (!m[curr])
            {
                m[curr]++;
            }
            else if (m[curr] != -1000)
            {
                v1.push_back(curr);
                m[curr] = -1000;
            }
            i++;
        }
        return v1;
    }
};

// SOLN IN MORE OPTIMISED WAY
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int> counter;
        vector<string> res;

        if (s.size() < 10)
            return res;

        for (int i = 0; i < s.size() - 9; i++)
            counter[s.substr(i, 10)]++;

        for (auto a : counter)
            if (a.second > 1)
                res.push_back(a.first);

        return res;
    }
};