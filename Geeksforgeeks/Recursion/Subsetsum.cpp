/*
Subset Sums
Basic Accuracy: 56.36% Submissions: 15779 Points: 1
Given a list arr of N integers, print sums of all subsets in it.

Note: Return all the element is increasing order.

Example 1:

Input:
N = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then
Sum = 2+3 = 5.
Example 2:

Input:
N = 3
arr = {5, 2, 1}
Output:
0 1 2 3 5 6 7 8
Your Task:
You don't need to read input or print anything. Your task is to complete the function subsetSums() which takes a list/vector and an integer N as an input parameter and return the list/vector of all the subset sums.

Expected Time Complexity: O(2N)
Expected Auxiliary Space: O(2N)

Constraints:
1 <= N <= 15
0 <= arr[i] <= 104
*/
#include <bits/stdc++.h>
using namespace std;
// Using extra space for current vector
class Solution
{
public:
    vector<int> op;
    void permute(int index, vector<int> nums, vector<int> curr)
    {
        if (index >= nums.size())
        {
            int s = 0;
            for (int i = 0; i < curr.size(); i++)
                s += curr[i];
            op.push_back(s);
            return;
        }
        permute(index + 1, nums, curr);
        curr.push_back(nums[index]);
        permute(index + 1, nums, curr);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> curr;
        permute(0, arr, curr);
        return op;
    }
};
// Without extra space
// class Solution
// {
// public:
//     vector<int> op;
//     void permute(int index, vector<int> nums, int s)
//     {

//         op.push_back(s);
//         return;
//     }
//     permute(index + 1, nums, s);
//     s = s + nums[index];
//     permute(index + 1, nums, s);
// } vector<int> subsetSums(vector<int> arr, int N)
// {
//     // Write Your Code here
//     vector<int> curr;
//     int s = 0;
//     permute(0, arr, s);
//     return op;
// }
// }
// ;