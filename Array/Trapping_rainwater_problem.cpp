/*
42. Trapping Rain Water
Hard

16512

235

Add to List

Share
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.



Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/
#include <bits/stdc++.h>
using namespace std;
// OPTIMISED APPROACH
int trap(vector<int> &height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    // To assure us that at certain point we can trap water as left height>=curr point height      either from right or left
    int left_max = 0, right_max = 0;
    while (left < right)
    {
        // Means there is probability of storin g water since right height is greter
        // But aclear ide ais given by max left height
        if (height[left] <= height[right])
        {
            // If height is gtreater thn or equal to means it's not possible to store water at current block
            if (height[left] >= left_max)
            {
                left_max = height[left];
            }
            // But if height on left is greater and since we are in this if blog we already know that height on right is greater hence we can store water
            else
            {
                ans += (left_max - height[left]);
            }
            left++;
        }
        // Means left siude has greater height
        else
        {
            // If curr height is greater thn or equal to max height means we cannot store water as it'll  be pre out
            if (height[right] >= right_max)
            {
                right_max = height[right];
            }
            // But if height is less thn max height means we can store water since we also have assurance that left  height is greater due to wghich we are in this else blog
            else
            {
                ans += (right_max - height[right]);
            }
            right--;
        }
    }
    return ans;
}

// BRUTE FORCE -II
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int sz = height.size();
        vector<int> toleft(sz, 0), toright(sz, 0);
        toright[0] = height[0];
        // Making toright array
        for (int i = 1; i < sz; i++)
        {
            if (height[i] > toright[i - 1])
            {
                toright[i] = height[i];
            }
            else
            {
                toright[i] = toright[i - 1];
            }
        }
        // Making toleft array
        toleft[sz - 1] = height[sz - 1];
        for (int i = sz - 2; i >= 0; i--)
        {
            if (height[i] > toleft[i + 1])
            {
                toleft[i] = height[i];
            }
            else
            {
                toleft[i] = toleft[i + 1];
            }
        }
        //    cout<<"\n toright: ";
        // for(auto e:toright){
        //     cout<<e<<" ";
        // }
        //  cout<<"\n toleft:  ";
        // for(auto e:toleft){
        //     cout<<e<<" ";
        // }
        // Finding water containing capacity
        int i = 0, j = 0, sum = 0;
        for (i = 0; i < sz; i++)
        {

            int val = (min(toright[i], toleft[j]) - height[i]);
            sum += val;
            j++;
        }

        return sum;
    }
};