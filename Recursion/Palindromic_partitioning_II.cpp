/*

132. Palindrome Partitioning II
Hard

3080

76

Add to List

Share
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.



Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans = INT_MAX;
    void permute(int start, string s, int c)
    {
        if (start >= s.size())
        {
            ans = min(ans, c - 1);
            // cout<<c<<" "<<s.size()<<endl;
            // if(c==s.size() ) ans=0;
            return;
        }

        for (int i = start; i < s.size(); i++)
        {
            if (ispalin(start, i, s))
            {
                permute(i + 1, s, c + 1);
            }
        }
    }
    bool ispalin(int i, int j, string s)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s)
    {
        if (ispalin(0, s.size() - 1, s))
            return 0;
        permute(0, s, 0);
        return ans;
    }
};