/*
557. Reverse Words in a String III
Easy

2277

143

Add to List

Share
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.



Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"
*/
#include <bits/stdc++.h>
using namespace std;
// BETTER APPROACH
class Solution
{
public:
    string reverseWords(string s)
    {
        size_t front = 0;
        for (int i = 0; i <= s.length(); ++i)
        {
            if (i == s.length() || s[i] == ' ')
            {
                reverse(&s[front], &s[i]);
                front = i + 1;
            }
        }

        return s;
    }
};
class Solution
{
public:
    string reverse(string s)
    {
        // cout<<s<<endl;
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            swap(s[i++], s[j--]);
        }
        //  cout<<s<<endl;
        return s;
    }
    string reverseWords(string s)
    {
        string s1 = "";
        s += " ";
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            s1 += s[i];
            if (s[i + 1] == ' ')
            {
                i++;
                res += reverse(s1);
                if (i != s.size() - 1)
                {
                    res += " ";
                }

                s1 = "";
            }
        }
        return res;
    }
};