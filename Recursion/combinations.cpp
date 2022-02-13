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
// Optimised solution
class Solution
{
public:
    // Better then Brute force
    // unordered_map<int,int> m;
    vector<vector<int>> op;
    void perm(vector<int> curr, int val, int k, int start)
    {
        if (curr.size() >= k)
        {
            // If size becomes >=k i.e ==k push into op and return
            op.push_back(curr);
            return;
        }
        for (int i = start; i <= val; i++)
        {
            // To avoid duplicate pairing
            // Push current elemet , to avoid duplicate while calling fn when pass starting value as i+1
            // i.e given k=2
            // First time curr[1]
            // Calling permut([1],4,2,2)
            // Again into this loop but loop starts with given satrt index i.e 2
            // so it becomes[1,2], thn 2 popped, [1,3] , 3 popped [1,4]
            // Then we come back to first call with i=2 and curr=[]
            // We push 2 into curr[2]
            // We call permute([2],4,2,3)
            // Again since size is small we loop
            //[2,3] pop 3, [2,4] , pop 4
            // Again come back to first call ,and make curr[3] and so on
            curr.push_back(i);
            // m[i]++;
            perm(curr, val, k, i + 1);
            // m[i]--;
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {

        vector<int> curr;
        perm(curr, n, k, 1);

        return op;
    }
};
class Solution
{
public:
    // Better then Brute force
    set<vector<int>> op;
    void perm(vector<int> curr, int val, int k)
    {
        if (curr.size() >= k)
        {
            sort(curr.begin(), curr.end());
            op.insert(curr);
            return;
        }
        for (int i = 1; i <= val; i++)
        {
            // To avoid duplicate pairing
            if (find(curr.begin(), curr.end(), i) == curr.end())
            {
                curr.push_back(i);
                perm(curr, val, k);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> op1;
        vector<int> curr;
        perm(curr, n, k);
        for (auto e : op)
        {
            op1.push_back(e);
        }
        return op1;
    }
};
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