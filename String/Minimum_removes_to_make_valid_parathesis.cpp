/*
1249. Minimum Remove to Make Valid Parentheses
Medium

3406

67

Add to List

Share
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.


Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s1)
    {
        int n = s1.size(), i = 0;
        stack<char> s;
        vector<int> op;
        string res = "";
        while (i < n)
        {
            if (s1[i] == '(')
            {
                // As you encounter an opening bracket
                // Push it into the stack
                // Push it's index into op
                // Such that this index will be pop_out when when
                // corresponding closing bracket is found
                // If no closing bracket is found
                // Means it's an invalid index and hence remain in
                // OP array so that we can ignore element at this index
                s.push('(');
                op.push_back(i);
            }
            else if (s1[i] == ')' && !s.empty() && s.top() == '(')
            {
                // If clsing bracket corresponding to opening bracket is found
                // Pop-out opening brcaket as well as index of opening bracket
                // As we know that set of brcakets is valid
                op.pop_back();
                s.pop();
            }
            // If saw a closing brcaket with no open ing bracket
            // Indicated by empty stack
            // Push it's index in  op array so as to ignore it
            else if (s1[i] == ')' && s.empty())
            {
                op.push_back(i);
            }
            i++;
        }

        i = 0;
        while (i < n)
        {
            // If i is in indexes to be ignored, ignore it
            if (find(op.begin(), op.end(), i) != op.end())
                i++;
            // Else push character in resultant string
            else
                res += s1[i++];
        }
        return res;
    }
};