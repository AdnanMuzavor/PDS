/*
784. Letter Case Permutation
Medium

2945

136

Add to List

Share
Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. Return the output in any order.



Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]
*/
#include <bits/stdc++.h>
using namespace std;
//BRUTE FORCE
class Solution
{
public:
    void dfs(vector<string> &op, string s, int i)
    {

        if (i > s.length())
        {
            return;
        };
        if (find(op.begin(), op.end(), s) == op.end())
        {
            op.push_back(s);
            // dfs(op,s,i-1);
        }
        int val = s[i];
        //If letter is small process it before making capital and after making capital
        if (val >= 65 && val <= 90)
        {
            dfs(op, s, i + 1);
            s[i] = s[i] + 32;
            dfs(op, s, i + 1);
        }
        //If letter is capital process it before making small and after making small
        else if (val >= 97 && val <= 122)
        {
            dfs(op, s, i + 1);
            s[i] = s[i] - 32;
            dfs(op, s, i + 1);
        }
        //If it's not a letter process next character
        else
        {
            dfs(op, s, i + 1);
        }
    }
    vector<string> letterCasePermutation(string s)
    {
        vector<string> op;

        // A->65, Z->90
        // a->97, z->122
        // small letter-32 = capital letter
        // capital letter+32 =small letter
        dfs(op, s, 0);
        return op;
    }
};