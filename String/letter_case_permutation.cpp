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
// OPTIMISED SOLUTION
class Solution
{
public:
    vector<string> ans;
    void permut(string curr, string s, int i)
    {
        // If i==length of string s, means we have tracersed and
        // processed the string so we can push it into the ans
        if (i >= s.length())
        {
            ans.push_back(curr);
            return;
        }
        // If current element is digit we simply push it into the
        // current string and go to next index
        if (isdigit(s[i]))
        {
            curr.push_back(s[i]);
            permut(curr, s, i + 1);
        }
        else
        {
            // If character is alphabet

            // First processing by keeping alphabet lower case
            string c1 = curr;
            c1.push_back(tolower(s[i]));
            permut(c1, s, i + 1);

            // Thn procesing by making alphabet upper case
            string c2 = curr;
            c2.push_back(toupper(s[i]));
            permut(c2, s, i + 1);
        }
    }
    vector<string> letterCasePermutation(string s)
    {
        ans.clear(); // Removing garbage values if any
        permut("", s, 0);
        return ans;
    }
};
// BRUTE FORCE
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
        // If letter is small process it before making capital and after making capital
        if (val >= 65 && val <= 90)
        {
            dfs(op, s, i + 1);
            s[i] = s[i] + 32;
            dfs(op, s, i + 1);
        }
        // If letter is capital process it before making small and after making small
        else if (val >= 97 && val <= 122)
        {
            dfs(op, s, i + 1);
            s[i] = s[i] - 32;
            dfs(op, s, i + 1);
        }
        // If it's not a letter process next character
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