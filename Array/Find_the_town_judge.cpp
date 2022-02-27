/*
997. Find the Town Judge
Easy

3154

241

Add to List

Share
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.



Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> in(n + 2, 0);
        vector<int> ot(n + 2, 0);
        int ans = 1;
        for (int i = 0; i < trust.size(); i++)
        {
            ot[trust[i][0]]++; // trust[i][0] is giving trust
            in[trust[i][1]]++; // trust[i][1] is gaining trust
            // If current person doesnt trust any other person , he can be judge
            if (ot[trust[i][1]] == 0)
                ans = trust[i][1];
        }
        for (int i = 0; i <= n + 1; i++)
        {
            // if i is assumed to be judge but it's not trusted by everyone else
            if (i == ans && in[i] != n - 1)
                return -1;
            // if i is assume dto be judge but it trust someone else
            if (i == ans && ot[i] > 0)
                return -1;
        }
        // means ans is judge, it's trusted by all and it doesnt trust anybody else
        return ans;
    }
};