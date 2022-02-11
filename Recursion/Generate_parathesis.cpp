/*
22. Generate Parentheses
Medium

11567

451

Add to List

Share
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.



Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
*/
#include <bits/stdc++.h>
using namespace std;
//BRUTE FORCE
class Solution
{
public:
    bool validate(string s)
    {
        stack<char> s1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                s1.push('(');
            else if (s[i] == ')' && s1.empty())
                return false;
            else if (s[i] == ')' && s1.top() == '(')
                s1.pop();
        }
        if (!s1.empty())
            return false;
        return true;
    }
    set<string> op;
    void permute(int start, string temp)
    {
        // Pushing each combination into o/p set
        if (start >= temp.size())
        {

            op.insert(temp);
            return;
        }
        for (int i = start; i < temp.size(); i++)
        {
            swap(temp[start], temp[i]);
            permute(start + 1, temp);
            swap(temp[i], temp[start]);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        int k = n;
        string s = "";
        vector<string> op1;
        while (k--)
        {
            s += "(";
        }
        while (n--)
        {
            s += ")";
        }
        permute(0, s);
        for (auto e : op)
        {
            // Adding only those as o/p which are valid
            if (validate(e))
            {
                op1.push_back(e);
            }
        }
        return op1;
    }
};