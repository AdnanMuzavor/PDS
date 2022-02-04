/*
18. 4Sum
Medium

5459

629

Add to List

Share
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.



Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/
#include <bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // O(N^3 LOGN+ N LOGN)
        // N^3 FOR 3 LOOPS AND LOGN FOR BINARY SEARCH
        // NLOGN FOR SORTING
        int n = nums.size();
        // TO keep track of unique elements
        set<vector<int>> op1;
        // To return main output
        vector<vector<int>> op2;
        vector<int> v;
        // Sorting so that we can use binary search to find the forth element
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    // Binary search procedure to find the forth element
                    long long int newtarget = (long long int)target - (long long int)nums[i] - (long long int)nums[j] - (long long int)nums[k];
                    int l = k + 1, h = n - 1;
                    while (l <= h)
                    {
                        int mid = (l + h) / 2;
                        if (nums[mid] == newtarget)
                        {
                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[k]);
                            v.push_back(nums[mid]);
                            op1.insert(v);
                            v.clear();
                            break;
                        }
                        else if (nums[mid] < newtarget)
                        {
                            l = mid + 1;
                        }
                        else
                        {
                            h = mid - 1;
                        }
                    }
                }
            }
        }
        // Pushing output in array/vector type
        for (auto e : op1)
            op2.push_back(e);
        return op2;
    }
};
// OPTIMISED APPROACH
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // O(N^2 LOGN+ N LOGN)
        // N^3 FOR 3 LOOPS AND LOGN FOR BINARY SEARCH
        // NLOGN FOR SORTING
        int n = nums.size();
        // TO keep track of unique elements
        set<vector<int>> op1;
        // To return main output
        vector<vector<int>> op2;
        vector<int> v;
        // Sorting so that we can use binary search to find the forth element
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // Binary search procedure to find the third and forth element
                long long int newtarget = (long long int)target - (long long int)nums[i] - (long long int)nums[j];
                int l = j + 1, h = n - 1;
                while (l < h)
                {

                    if (nums[l] + nums[h] == newtarget)
                    {
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[l]);
                        v.push_back(nums[h]);
                        op1.insert(v);
                        v.clear();
                        int x = nums[l], y = nums[h];
                        // escaping duplicates
                        while (l < h && nums[l] == x)
                            l++;
                        while (h > l && nums[h] == y)
                            h--;
                    }
                    else if (nums[l] + nums[h] < newtarget)
                    {
                        l++;
                    }
                    else
                    {
                        h--;
                    }
                }
                // moving j to skip duplicates as it'll give same result
                while (j + 1 < n && nums[j] == nums[j + 1])
                    j++;
            }
            // moving i to skip duplicates as it'll give same result
            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;
        }
        // Pushing output in array/vector type
        for (auto e : op1)
            op2.push_back(e);
        return op2;
    }
};

// SAME CAN BE DONE WITHOUT SET
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // O(N^3 LOGN+ N LOGN)
        // N^3 FOR 3 LOOPS AND LOGN FOR BINARY SEARCH
        // NLOGN FOR SORTING
        int n = nums.size();
        // TO return o/p
        vector<vector<int>> op1;

        vector<int> v;
        // Sorting so that we can use binary search to find the forth element
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // Binary search procedure to find the third and forth element
                long long int newtarget = (long long int)target - (long long int)nums[i] - (long long int)nums[j];
                int l = j + 1, h = n - 1;
                while (l < h)
                {

                    if (nums[l] + nums[h] == newtarget)
                    {
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[l]);
                        v.push_back(nums[h]);
                        op1.push_back(v);
                        v.clear();
                        int x = nums[l], y = nums[h];
                        // escaping duplicates
                        while (l < h && nums[l] == x)
                            l++;
                        while (h > l && nums[h] == y)
                            h--;
                    }
                    else if (nums[l] + nums[h] < newtarget)
                    {
                        l++;
                    }
                    else
                    {
                        h--;
                    }
                }
                // moving j to skip duplicates as it'll give same result
                while (j + 1 < n && nums[j] == nums[j + 1])
                    j++;
            }
            // moving i to skip duplicates as it'll give same result
            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;
        }

        return op1;
    }
};