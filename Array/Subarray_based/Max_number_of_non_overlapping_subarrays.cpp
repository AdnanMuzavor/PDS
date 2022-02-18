/*
1546. Maximum Number of Non-Overlapping Subarrays With Sum Equals Target
Medium

687

15

Add to List

Share
Given an array nums and an integer target, return the maximum number of non-empty non-overlapping subarrays such that the sum of values in each subarray is equal to target.



Example 1:

Input: nums = [1,1,1,1,1], target = 2
Output: 2
Explanation: There are 2 non-overlapping subarrays [1,1,1,1,1] with sum equals to target(2).
Example 2:

Input: nums = [-1,3,5,1,4,2,-9], target = 6
Output: 2
Explanation: There are 3 subarrays with sum equal to 6.
([5,1], [4,2], [3,5,1,4,2,-9]) but only the first 2 are non-overlapping.
*/
#include <bits/stdc++.h>
using namespace std;

// Unworking brute force
class Solution
{
public:
    // upper and lower indexes tracker
    vector<pair<int, int>> pr;
    // Upper bound index of last subarray
    int upper = -1;
    // op keeper
    vector<vector<pair<int, int>>> op;
    void recurr(vector<pair<int, int>> curr, int target, vector<int> nums, int start, int maintarget)
    {
        if (target > maintarget)
            return;
        if (curr.size() == 1 && curr[0].first == maintarget)
        {
            op.push_back(curr);
            return;
        }
        if (target == maintarget)
        {
            if (curr[0].second > upper)
            {

                for (int i = 1; i < curr.size(); i++)
                {
                    if (abs(curr[i].second - curr[i - 1].second) > 1)
                        return;
                }
                int i = 0;
                upper = curr[curr.size() - 1].second;
                cout << "upper index is: " << upper << endl;
                // while(curr[i].first==0){
                //     i++;
                // }
                // upper=curr[curr.size()-1].second;
                op.push_back(curr);
            }

            return;
        }
        for (int i = start; i < nums.size(); i++)
        {

            curr.push_back({nums[i], i});
            recurr(curr, target + nums[i], nums, i + 1, maintarget);
            curr.pop_back();
        }
    }
    int maxNonOverlapping(vector<int> &nums, int target)
    {
        vector<pair<int, int>> curr;

        recurr(curr, 0, nums, 0, target);
        // for(auto e:op){
        //     for(auto ele : e){
        //         cout<<ele.first<<" ";
        //     }
        //     cout<<endl;
        // }
        return op.size();
    }
};

// BRUET FORCE-II generate all subarrays ,keep track of upper bounds and return ans

// Optimised (NEET CODE)appraoch onlt thing here we are taking set for unique sums and when same sum is found we we reach our target so we increment count
// and clear/reset array and sum

class Solution
{
public:
    int maxNonOverlapping(vector<int> &nums, int target)
    {
        unordered_set<int> m;
        m.insert(0);
        int sum = 0, c = 0;
        for (auto e : nums)
        {
            sum += e;
            if (m.count(sum - target))
            {
                c++;
                sum = 0;
                m = {0};
            }
            else
            {
                m.insert(sum);
            }
        }
        return c;
    }

    // HOW??
    //[1,1,1,1] k=2
    // set [0]
    // sum=0
    // int i=0    sum=1        (1-2=-1) not in set                    hence set[0,1],ans=0
    // int i=1    sum=2        (2-2=0) is in set->first pair found    hence set[0],sum=0,ans=1
    // int i=2    sum=1        (1-2=-1) not in set                    hence set[1],ans=1
    // int i=3    sum=2        (2-2=0) is in set                      hence set[0],sum[0],ans=2
};