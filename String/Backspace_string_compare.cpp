/*
844. Backspace String Compare
Easy

3467

159

Add to List

Share
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.



Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        string s1 = "", s2 = "";
        int n1 = s.size(), n2 = t.size();
        for (int i = 0; i < n1; i++)
        {
            if (s[i] != '#')
            {
                s1.push_back(s[i]);
            }
            else
            {
                if (s1.size() != 0)
                    s1.pop_back();
            }
        }
        for (int i = 0; i < n2; i++)
        {
            if (t[i] != '#')
            {
                s2.push_back(t[i]);
            }
            else
            {
                if (s2.size() != 0)
                    s2.pop_back();
            }
        }
        // cout<<s1<<endl;
        //  cout<<s2<<endl;
        if (s1 == s2)
            return true;
        return false;
    }
};
