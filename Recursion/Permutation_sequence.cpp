/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.



Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
*/
#include <bits/stdc++.h>
using namespace std;
// BRUTE FORCE(N+LOGN)
// SPACE O(N)
class Solution
{
public:
    vector<string> op;
    void permute(vector<int> nums, int start, string res)
    {
        if (start >= nums.size())
        {
            string soln = "";
            for (auto e : nums)
            {
                soln += to_string(e);
            }
            op.push_back(soln);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            swap(nums[start], nums[i]);
            permute(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
    string getPermutation(int n, int k)
    {
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++)
        {
            nums[i] = i + 1;
        }

        string res = "";
        permute(nums, 0, res);
        sort(op.begin(), op.end());

        return op[k - 1];
    }
};
// O(N^2)+O(N)
// Refer striver's video
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> nums;
        int fact = 1;
        for (int i = 1; i < n; i++)
        {
            nums.push_back(i);
            fact = fact * i;
        }
        nums.push_back(n);
        k = k - 1; // as we are following zero based indexing
        vector<string> op;
        string res = "";
        while (true)
        {
            res += to_string(nums[k / fact]);
            nums.erase(nums.begin() + k / fact);
            if (nums.size() == 0)
                break;
            k = k % fact;
            fact = fact / nums.size();
        }
        return res;
    }
};
