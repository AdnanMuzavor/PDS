/*
128. Longest Consecutive Sequence
Medium

8166

362

Add to List

Share
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.



Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        //  Brute force approach without sorting
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return 1;
        // sort(nums.begin(),nums.end()); //O(NlogN (sorting) +N(iteration))
        unordered_map<int, int> m;
        for (auto e : nums)
        {
            m[e]++;
        }
        int len = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!m[nums[i] - 1])
            {
                int start = nums[i];
                int next = start + 1;
                while (m[next])
                {
                    next++;
                }
                len = max(len, next - start);
            }
        }
        return len;
    }
};
