/*
11. Container With Most Water
Medium

14204

856

Add to List

Share
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.



Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
*/
#include <bits/stdc++.h>
using namespace std;
// BRUTE FORCE CHECK FOR EACH HEIGHT
class Solution
{
public:
    int maxi = INT_MIN;
    int accum(int h1, int h2, int diff)
    {
        //  cout<<"checking h1: "<<h1<<" h2: "<<h2<<" at diff: "<<diff<<endl;
        return diff * min(h1, h2);
    }
    int maxArea(vector<int> &height)
    {
        int sz = height.size();
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                if (j > i)
                {
                    maxi = max(maxi, accum(height[i], height[j], j - i));
                }
            }
        }
        return maxi;
    }
};
// Optimised O(N)
class Solution
{
public:
    int maxi = INT_MIN;
    int accum(int h1, int h2, int diff)
    {
        // diff can be considered an lenght of the container
        // min among h1 and h2 will be hright of container
        // if we chose maximum height thn water might flow down
        return diff * min(h1, h2);
    }
    int maxArea(vector<int> &height)
    {
        int sz = height.size();
        int i = 0, j = sz - 1;
        while (i < j)
        {
            // Calculating maxi at each step
            maxi = max(maxi, accum(height[i], height[j], j - i));
            // If one of the either left/right height is small we shift accordingly
            if (height[i] <= height[j])
                i++;
            else
                j--;
        }
        return maxi;
    }
};