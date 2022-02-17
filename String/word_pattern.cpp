/*
290. Word Pattern
Easy

3315

378

Add to List

Share
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.



Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
*/
#include <bits/stdc++.h>
using namespace std;
// UNSERDTANDING PURPOSE CODE
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        s += ' ';
        //  if(pattern==s) return false;
        // Map a character in pattern with word in string
        unordered_map<char, string> m;
        // Map string with that character
        unordered_map<string, char> m2;
        // Splitting a into words
        vector<string> v;
        for (int i = 0; i < s.size(); i++)
        {
            string s1 = "";
            while (i < s.size() && (s[i] != ' '))
            {
                //    cout<<"yes"<<s[i]<<endl;
                s1 += s[i];
                i++;
            }

            v.push_back(s1);
        }
        // cout<<pattern.size()<<" "<<v.size()<<endl;
        // If pattern given and words are not of equal size
        if (pattern.size() < v.size() || v.size() < pattern.size())
            return false;
        // Initiualising character map for pattern
        for (auto e : pattern)
        {
            m[e] = ".";
        }
        // Initialing string map for strings
        for (auto e : v)
        {
            m2[e] = '.';
        }
        // Map char with word
        int i = 0;
        for (auto e : pattern)
        {
            // If char is not mapped and string is not mapped
            if (m[e] == "." && m2[v[i]] == '.')
            {
                m[e] = v[i];
                m2[v[i]] = e;
            }
            else
            {

                // If mapped and if it's same i.e char mapped with same string/char
                if (m[e] == v[i] && m2[v[i]] == e)
                    cout << "Oh it's same" << endl;
                // If same string mapped to different char
                else
                {
                    // If it's mapped but string and char are not matching thn
                    // It's wrong and we should return false
                    cout << e << " was already mapped with: " << m[e] << endl;
                    cout << "so could'nt be mapped with other character like: " << v[i] << endl;
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};
// CLEAN CODE
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        s += ' ';
        //  if(pattern==s) return false;
        // Map a character in pattern with word in string
        unordered_map<char, string> m;
        // Map string with that character
        unordered_map<string, char> m2;
        // Splitting a into words
        vector<string> v;
        for (int i = 0; i < s.size(); i++)
        {
            string s1 = "";
            while (i < s.size() && (s[i] != ' '))
            {

                s1 += s[i];
                i++;
            }

            v.push_back(s1);
        }
        // cout<<pattern.size()<<" "<<v.size()<<endl;
        // If pattern given and words are not of equal size
        if (pattern.size() < v.size() || v.size() < pattern.size())
            return false;
        // Initiualising character map for pattern
        for (auto e : pattern)
        {
            m[e] = ".";
        }
        // Initialing string map for strings
        for (auto e : v)
        {
            m2[e] = '.';
        }
        // Map char with word
        int i = 0;
        for (auto e : pattern)
        {
            // If char is not mapped and string is not mapped
            if (m[e] == "." && m2[v[i]] == '.')
            {
                m[e] = v[i];
                m2[v[i]] = e;
            }
            else
            {

                // If mapped and if it's same i.e char mapped with same string/char
                if (m[e] == v[i] && m2[v[i]] == e)
                {
                }
                // If same string mapped to different char
                else
                {

                    return false;
                }
            }
            i++;
        }
        return true;
    }
};