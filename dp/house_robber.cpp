/*
198. House Robber
Medium

10591

230

Add to List

Share
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.



Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/

// class Solution {
// public:
// RECURSIVE BRUTE FORCE APPROACH
//     int solve(vector<int> &dp,vector<int> n,int i){
//         //Actuallu used when your dp exceeds nums.size()
//         if(i<=-1) return 0;
//         //when dp[i] is available
//         if(dp[i]!=-1) return dp[i];
//         //calculating considering current house and hence i-2
//         int op1=n[i]+solve(dp,n,i-2); //option-1 if choose curr house
//         int op2=solve(dp,n,i-1); //option-2 if chose prev house
//         return max(op1,op2); //choosing option giving max profit
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n,-1);
//         cout<<dp[0]<<endl;
//         int sum=solve(dp,nums,n-1);
//         return sum;
//     }
// };
#include <bits/stdc++.h>
using namespace std;
// Optimised solution without recursion
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        // if(n==2) return max(nums[0],nums[1]);
        int *dp = new int[n];
        dp[0] = nums[0];               // profit till house zero/1 house case
        dp[1] = max(nums[0], nums[1]); // If 2 houses choose profitable one
        for (int i = 2; i < n; i++)
        {

            // Choosing current house i.e nums[i] means combo of
            // current house nums[i] and profit till nums[i-2] house
            // hence nums[i]+dp[i-2]

            // If we don't choose current house, we can choose, means we lke to opt for combo
            // pf prev house i.e dp[i-1]

            // Choice depends upon which is maximum among two
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};