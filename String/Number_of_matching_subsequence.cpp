/*
792. Number of Matching Subsequences
Medium

2676

141

Add to List

Share
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".


Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

// O(N^2)
class Solution
{
public:
    bool issub(string s1, string s)
    {
        int res = 0;
        if (s1 == s)
            return true;
        int n1 = s1.size();
        int n2 = s.size();
        int j = 0;
        if (n2 < n1)
            return false;
        for (int i = 0; i < n1; i++)
        {
            while (j < n2 && s1[i] != s[j])
                j++;
            if (j < n2)
                res++;
            j++;
        }
        if (res == n1)
            return true;
        return false;
    }
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int c = 0;
        // Checking if each word is words is subsequence of s
        for (auto strs : words)
        {
            // This function checks is word is subsequence of s
            if (issub(strs, s))
            {
                c++;
            }
        }
        return c;
    }
};

// O(2^n+K) n is number of chars in string s

class Solution
{
public:
    unordered_map<string, int> mp;
    int ans = 0;
    void permute(vector<char> curr, string s, int start)
    {

        string res = "";
        for (auto e : curr)
            res += e;
        if (mp[res] == 10)
        {
            ans++;
            mp[res] = -10;
        }

        for (int i = start; i < s.size(); i++)
        {
            curr.push_back(s[i]);
            permute(curr, s, i + 1);
            curr.pop_back();
        }
    }
    int numMatchingSubseq(string s, vector<string> &words)
    {
        for (auto e : words)
        {
            mp[e] = 10;
        }
        vector<char> curr;
        permute(curr, s, 0);
        //  for(auto e:st) cout<<e<<" ";
        return ans;
    }
};