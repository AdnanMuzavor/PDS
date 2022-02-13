/*
48. Rotate Image
Medium

8030

454

Add to List

Share
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // BRUTE FORCE
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> soln(rows, vector<int>(cols, 0));
        int co = 0;
        // Rotaing matrix i.e row to coln and coln to row
        // Amd storing in extra maxtrix
        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = 0; j < cols; j++)
            {
                soln[j][co] = matrix[i][j];
            }
            co++;
        }
        // Copying extra matrix back into original matrix
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = soln[i][j];
            }
        }
    }
};
// METHOD=II, OPTIMISED SOLN
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // BRUTE FORCE
        int rows = matrix.size();
        int cols = matrix[0].size();

        int co = 0;

        // Taking transpose
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Reversing each row in transpose
        for (int i = 0; i < rows; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};