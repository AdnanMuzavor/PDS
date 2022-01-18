/*
4. Median of Two Sorted Arrays
Hard

14388

1820

Add to List

Share
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int n1 = nums1.size();
        int n2 = nums2.size();
        //         int k=n1-1;
        //         while(i<n1 && j<n2){
        //             if(nums1[i]<nums2[j]){
        //                 i++;
        //             }
        //             else{
        //                 swap(nums1[k--],nums2[j++]);
        //             }
        //         }
        //         sort(nums1.begin(),nums1.end());
        //         sort(nums2.begin(),nums2.end());
        //         for(auto e:nums1) cout<<e<<" ";
        //         for(auto e:nums2) cout<<e<<" ";
        //         cout<<endl;
        //         cout<<(n1+n2)/2<<endl;
        //         int mid=(n1+n2)/2;

        //         if(mid<n1){
        //             return nums1[mid];
        //         }
        //         else{
        //             return nums2[abs(n2-mid)-1];
        //         }
        int total = n1 + n2;
        if (total % 2 == 0)
        {
            int i = 0, j = 0;
            // Average of 2 mids
            int mid = total / 2;
            cout << "mid: " << mid << endl;
            int m1 = 0, m2 = 0;
            for (int c = 0; c <= mid; c++)
            {
                cout << m1 << " " << m2 << endl;
                m2 = m1;
                if (i < n1 && j < n2 && nums1[i] <= nums2[j])
                {
                    // cout<<nums1[i]<<"i<j"<<endl;
                    m1 = nums1[i];
                    i++;
                }
                else if (j < n2 && i < n1 && nums2[j] < nums1[i])
                {
                    // cout<<nums2[i]<<"j<i"<<endl;
                    m1 = nums2[j];
                    j++;
                }
                else if (i >= n1 && j < n2)
                {
                    // cout<<nums2[i]<<"i==n1"<<endl;
                    m1 = nums2[j];
                    j++;
                }
                else if (j >= n2 && i < n1)
                {
                    // cout<<nums1[i]<<"j==n2"<<endl;
                    m1 = nums1[i];
                    i++;
                }
            }
            // cout<<m2<<" "<<m1<<endl;
            return (double)(m1 + m2) / 2;
        }
        else
        {
            int i = 0, j = 0;
            // Mid element
            int mid = total / 2;
            cout << "mid: " << mid << endl;
            int m1 = 0;
            //,m2=nums2[j];
            for (int c = 0; c <= mid; c++)
            {
                // m2=m1;
                cout << m1 << endl;
                if (i < n1 && j < n2 && nums1[i] <= nums2[j])
                {
                    // cout<<nums1[i]<<"i<j"<<endl;
                    m1 = nums1[i];

                    i++;
                }
                else if (j < n2 && i < n1 && nums2[j] < nums1[i])
                {
                    // cout<<nums2[i]<<"j<i"<<endl;
                    m1 = nums2[j];
                    j++;
                }
                else if (i >= n1 && j < n2)
                {
                    // cout<<nums2[i]<<"i==n1"<<endl;
                    m1 = nums2[j];
                    j++;
                }
                else if (j >= n2 && i < n1)
                {
                    // cout<<nums1[i]<<"j==n2"<<endl;
                    m1 = nums1[i];
                    i++;
                }
            }
            // cout<<m2<<" "<<m1<<endl;
            return (double)m1;
        }
        return 1;
    }
};