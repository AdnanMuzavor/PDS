/*
59. Spiral Matrix II
Medium

2479

159

Add to List

Share
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.



Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> op(n, vector<int>(n, 0));

        int k = 1;

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int dest = 0;
        while (top <= bottom && left <= right)
        {
            if (dest == 0)
            {
                for (int i = left; i <= right; i++)
                {
                    op[top][i] = k;
                    k++;
                }
                top += 1;
            }
            else if (dest == 1)
            {
                for (int i = top; i <= bottom; i++)
                {
                    op[i][right] = k;
                    k++;
                }
                right -= 1;
            }
            else if (dest == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    op[bottom][i] = k;
                    k++;
                }
                bottom -= 1;
            }
            else
            {
                for (int i = bottom; i >= top; i--)
                {
                    op[i][left] = k;
                    k++;
                }
                left += 1;
            }
            dest = (dest + 1) % 4;
        }

        return op;
    }
};