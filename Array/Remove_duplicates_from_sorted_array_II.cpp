/*
80. Remove Duplicates from Sorted Array II
Medium

2696

872

Add to List

Share
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.



Example 1:

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

*/

#include <bits/stdc++.h>
using namespace std;
// Optimised soln
// check intrision from book
int removeDuplicates(vector<int> &nums)
{
    int n = nums.size(), count = 0;
    for (int i = 2; i < n; i++)
    {
        if (nums[i] == nums[i - 2 - count])
            count++;
        else
            nums[i - count] = nums[i];
    }
    return n - count;
}
// My soln
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int sz = nums.size();
        if (sz == 1 || sz == 2)
            return sz;
        // Store in map to keep record of occurence of each
        map<int, int> m;
        //  sort(m.begin(),m.end());
        for (auto e : nums)
        {
            m[e]++;
        }
        nums.clear();
        for (auto e : m)
        {
            // Elements which occur more thn twice should be there in array
            // only twice so pushing them twice
            if (e.second >= 2)
            {
                nums.push_back(e.first);
                nums.push_back(e.first);
                sz--;
            }
            // Else it means elemet occursb only once so
            // pushing into array only once
            else
            {
                nums.push_back(e.first);
                sz--;
            }
        }
        return nums.size();
    }
};