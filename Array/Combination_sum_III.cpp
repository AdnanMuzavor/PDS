/*
216. Combination Sum III
Medium

2538

72

Add to List

Share
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.



Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
*/
#include <bits/stdc++.h>
using namespace std;
// Making nums and thn passing
class Solution
{
public:
    void permute(vector<int> curr, vector<vector<int>> &op, vector<int> nums, int start, int k, int target)
    {
        if (curr.size() >= k)
        {
            if (target == 0)
                op.push_back(curr);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            if (nums[i] > target)
                return;
            curr.push_back(nums[i]);
            permute(curr, op, nums, i + 1, k, target - nums[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> op;
        vector<int> curr;
        vector<int> nums;
        for (int i = 1; i <= 9; i++)
            nums.push_back(i);
        permute(curr, op, nums, 0, k, n);

        return op;
    }
};
// Indirectly without using array
class Solution
{
public:
    void permute(vector<int> curr, vector<vector<int>> &op, int start, int k, int target)
    {
        if (curr.size() >= k)
        {
            if (target == 0)
                op.push_back(curr);
            return;
        }

        for (int i = start; i <= 9; i++)
        {
            if (i > target)
                return;
            curr.push_back(i);
            permute(curr, op, i + 1, k, target - i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> op;
        vector<int> curr;

        permute(curr, op, 1, k, n);
        return op;
    }
};