/*
54. Spiral Matrix
Medium

6131

788

Add to List

Share
Given an m x n matrix, return all elements of the matrix in spiral order.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> op;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int top = 0, bottom = rows - 1; // setting top and bottom pointer
        int left = 0, right = cols - 1; // setting right and left pointer
        int dest = 0;                   // destination
        // 0->means Left to Right
        // 1->means top to bottom
        // 2->means right to left
        // 3->means bottom to top
        while (top <= bottom && left <= right)
        {
            if (dest == 0)
            {
                // Move left to right
                for (int i = left; i <= right; i++)
                {
                    op.push_back(matrix[top][i]);
                }
                //  Incrementing top as row being traversed
                // i.e moving top to lower row
                top += 1;
            }
            else if (dest == 1)
            {
                // Move top to bottom
                for (int i = top; i <= bottom; i++)
                {
                    op.push_back(matrix[i][right]);
                }

                // decreming right i.e shifting right to left by 1
                right -= 1;
            }
            else if (dest == 2)
            {
                // Move right to left
                for (int i = right; i >= left; i--)
                {
                    op.push_back(matrix[bottom][i]);
                }
                // Moving bottom up
                bottom -= 1;
            }
            else
            {
                // Move bottom to top
                for (int i = bottom; i >= top; i--)
                {
                    op.push_back(matrix[i][left]);
                }
                // Moving left to a bit right
                left += 1;
            }

            // Update destination as it lies between 0-3
            dest = (dest + 1) % 4;
        }
        return op;
        // Keeping for pointers
    }
};