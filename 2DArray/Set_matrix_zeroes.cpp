/*
73. Set Matrix Zeroes
Medium

5812

453

Add to List

Share
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.



Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/
#include <bits/stdc++.h>
using namespace std;

// Contant space solution
void setZeroes(vector<vector<int>> &matrix)
{
    int col0 = 1; // To keep track of zeroth column if any elemet in this column is zero
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
        // If any element of zeroth column is zero
        if (matrix[i][0] == 0)
            col0 = 0;
        for (int j = 1; j < cols; j++)
        {
            // starting from j=1 because col0 will take care of col0
            if (matrix[i][j] == 0)
            {
                // If found zero making,setting flags that is
                // first block of that row and first block of that column
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    // Iterating matrix and setting to those blocks zero whose flag is set to zero
    for (int i = rows - 1; i >= 0; i--)
    {
        // starting from one because belwo statement will take care of zeroth column
        for (int j = cols - 1; j >= 1; j--)
        {
            // If flag is being set to zero
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
        // Using col0 to set zeroth column memebers zero
        if (col0 == 0)
            matrix[i][0] = 0;
    }
}
class Solution
{
public:
    void makezero(vector<vector<int>> &m, int rows, int cols, int cr, int cc)
    {
        // All rows of given column
        for (int i = 0; i < rows; i++)
        {
            m[i][cc] = 0;
        }
        // All cols of given row
        for (int j = 0; j < cols; j++)
        {
            m[cr][j] = 0;
        }
    }
    void setZeroes(vector<vector<int>> &matrix)
    {
        // For recording indices value zero
        vector<pair<int, int>> indices;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    indices.push_back({i, j});
                }
            }
        }
        for (int i = 0; i < indices.size(); i++)
        {
            // Sending these indices to function to make rows/cols zero
            makezero(matrix, rows, cols, indices[i].first, indices[i].second);
        }
    }
};