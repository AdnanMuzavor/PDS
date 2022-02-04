/*
77. Combinations
Medium

3589

121

Add to List

Share
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.



Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]
*/

#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE
class Solution
{
public:
    // Brute force
    vector<vector<int>> op;
    bool noduplicate(vector<int> v)
    {
        unordered_map<int, int> m;
        for (auto e : v)
        {
            if (m[e] == 10)
                return false;
            else
                m[e] = 10;
        }
        return true;
    }
    void perm(vector<int> curr, int val, int k)
    {
        if (curr.size() >= k)
        {
            // Checking if in current array same element is not used twice or more times
            if (noduplicate(curr))
            {
                // Sorting to see if this elemet was already pushed before
                sort(curr.begin(), curr.end());
                // If it's not found means it's new so we push into output
                if (find(op.begin(), op.end(), curr) == op.end())
                {
                    op.push_back(curr);
                }
            }
            return;
        }
        for (int i = 1; i <= val; i++)
        {
            curr.push_back(i);
            perm(curr, val, k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {

        vector<int> curr;
        perm(curr, n, k);
        return op;
    }
};