/*
49. Group Anagrams
Medium

8274

286

Add to List

Share
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        for (auto e : strs)
        {
            string t = e;
            // Getting common string eevry time wesort
            sort(e.begin(), e.end());
            // We push curr string into vector of corresponding anagram
            m[e].push_back(t);
        }
        vector<vector<string>> ans;
        for (auto e : m)
        {
            ans.push_back(e.second);
        }
        return ans;
    }
};

// Appraoch II->Generating common key manually
class Solution
{
public:
    string commonkey(string s)
    {
        string key = "";
        vector<int> v(26, 0);
        for (auto e : s)
            v[e - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            while (v[i] > 0)
            {
                key += (i + 'a');
                v[i]--;
            }
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        for (auto e : strs)
        {
            string t = e;
            //  sort(e.begin(),e.end());

            // Instead of sorting for generating common key
            // We can generate common key manually
            m[commonkey(e)].push_back(t);
        }
        vector<vector<string>> ans;
        for (auto e : m)
        {
            ans.push_back(e.second);
        }
        return ans;
    }
};
// Method-III keeping track of count  each chars in string
class Solution
{
public:
    string commonkey(string s)
    {
        string key = "";
        vector<int> v(26, 0);
        for (auto e : s)
            v[e - 'a']++;
        // Counting freq of each char and taking that as key
        for (int i = 0; i < 26; i++)
        {
            if (v[i] > 0)
            {
                key += to_string(v[i]) + char(i + 'a');
            }
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        for (auto e : strs)
        {
            string t = e;
            //  sort(e.begin(),e.end());

            // Instead of sorting for generating common key
            // We can generate common key manually
            m[commonkey(e)].push_back(t);
        }
        vector<vector<string>> ans;
        for (auto e : m)
        {
            ans.push_back(e.second);
        }
        return ans;
    }
};