/*
131. Palindrome Partitioning
Medium

6068

182

Add to List

Share
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.



Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void permute(vector<vector<string>> &ans, vector<string> curr, string s, int start)
    {
        if (start >= s.size())
        {
            ans.push_back(curr);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            // Starting point to point uptill which string is palindromic
            // And as we push palindromic substring into curr,
            // We go ahead looking for partitioning next part by sending i+1
            if (ispalin(s, start, i))
            {
                curr.push_back(s.substr(start, i - start + 1));
                permute(ans, curr, s, i + 1);
                curr.pop_back();
            }
        }
    }
    bool ispalin(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> curr;
        permute(ans, curr, s, 0);
        return ans;
    }
};