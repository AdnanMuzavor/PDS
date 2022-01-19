/*
20. Valid Parentheses
Easy

10731

442

Add to List

Share
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int i = 0;
        int l = s.size();
        if (l == 0 || l == 1)
        {
            return false;
        }
        stack<char> s1;
        while (s[i] != '\0')
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                s1.push(s[i++]);
            }
            else if (!s1.empty() && ((s[i] == ')' && s1.top() == '(') || (s[i] == '}' && s1.top() == '{') || (s[i] == ']' && s1.top() == '[')))
            {
                s1.pop();
                i++;
            }

            else
            {
                return false;
            }
        }
        if (s1.empty())
        {
            return true;
        }
        return false;
    }
};