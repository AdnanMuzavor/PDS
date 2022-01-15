/*
345. Reverse Vowels of a String
Easy

1379

1714

Add to List

Share
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.



Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        vector<pair<char, int>> vowel;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char s1 = s[i];
            //  cout<<s1<<endl;
            if (s1 == 'a' || s1 == 'e' || s1 == 'i' || s1 == 'o' || s1 == 'u' || s1 == 'A' || s1 == 'E' || s1 == 'I' || s1 == 'O' || s1 == 'U')
            {
                vowel.push_back({s1, i});
                count++;
            }
        }
        if (count == 0)
            return s;
        int i = 0, j = vowel.size() - 1;
        while (i < j)
        {
            swap(s[vowel[i].second], s[vowel[j].second]);
            i++;
            j--;
        }

        return s;
    }
};