/*
532. K-diff Pairs in an Array
Medium

2051

1903

Add to List

Share
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i < j < nums.length
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.



Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
*/
#include <bits/stdc++.h>
using namespace std;
// Easy to understand and optimised
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        int i = 0, j = 1;
        // j should always be higher
        // iT's sliding window technique
        while (i < n && j < n)
        {
            // Incase i==j thn we should move j ahead
            if (i == j)
            {
                j++;
                continue;
            }
            // Since j>i diff will be>=0
            int diff = nums[j] - nums[i];
            if (diff < k)
            {
                // if diff is less means bigger no should be incresed so j++
                j++;
            }
            else if (diff > k)
            {
                // if diff is greater and we make higher no more high thn it'll increase
                // so we increase lower index to minimise the diff
                i++;
            }
            else
            {
                // diff is equal
                count++;
                i++; // moving i to next elemet
                j++; // moving j to next element
                while (i < n && nums[i] == nums[i - 1])
                    i++; // to avoid duplicates
                while (j < n && nums[j] == nums[j - 1])
                    j++; // to avoid duplicates
            }
        }
        return count;
    }
};
// OPTIMISED
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;
        unordered_map<int, int> m;
        for (int n : nums)
            m[n]++;
        int cnt = 0;
        for (auto p : m)
        {
            if ((!k && p.second > 1) || (k && m.count(p.first + k)))
                ++cnt;
        }
        return cnt;
    }
};
// BRUTE FORCE
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        set<pair<int, int>> op;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++)
        {
            int newval = nums[i] + k;
            // cout<<newval<<endl;
            int l = i + 1, h = nums.size() - 1;
            // finding next element in further array
            while (l <= h)
            {
                int mid = (l + h) / 2;
                if (nums[mid] == newval)
                {
                    //   cout<<"yes"<<endl;
                    pair<int, int> p;
                    p = {newval, nums[mid]};
                    op.insert(p);
                    l++;
                    h--;
                    // To avoid duplicates
                    while (l < h && nums[l] == nums[mid])
                        l++;
                    while (h > l && nums[h] == nums[mid])
                        h--;
                }
                else if (nums[mid] < newval)
                    l++;
                else
                    h--;
            }
            // To avoid duplicates
            while (i + 1 < nums.size() && nums[i + 1] == newval - k)
                i++;
        }
        return op.size();
    }
};
