/*


941. Valid Mountain Array
Easy

1730

130

Add to List

Share
Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]



Example 1:

Input: arr = [2,1]
Output: false
Example 2:

Input: arr = [3,5,5]
Output: false
Example 3:

Input: arr = [0,3,2,1]
Output: true

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        if (arr.size() < 3)
            return false;
        int lastval = arr[0];
        int i = 1;
        // Travserse till you get the peak
        while (i < arr.size())
        {
            if (arr[i] > lastval)
            {
                lastval = arr[i];
            }
            // Breaking after reaching at peak
            else if (arr[i] < lastval)
            {
                break;
            }
            // If levelled is found i.e 2 array vals equal thn false
            else
            {
                return false;
            }
            // If there is just way to peak and no way down it's false
            if (i == arr.size() - 1)
                return false;
            i++;
        }
        // Indicates that there is only way down,no way up
        if (i == 1)
            return false;

        // Trvaersing fom peak till bottom
        while (i < arr.size())
        {
            if (arr[i] < lastval)
            {
                lastval = arr[i];
            }
            else
            {
                // If there is again up route in between
                return false;
            }
            i++;
        }
        return true;
        //         if(arr.size()<3)return false;
        //         int i=0;
        //         while(i+1<arr.size() && arr[i]<arr[i+1]) i++;
        //         if(i==0 || i==arr.size()-1) return false;

        //         while(i+1<arr.size() && arr[i]>arr[i+1]) i++;
        //         return i==arr.size()-1;
    }
};