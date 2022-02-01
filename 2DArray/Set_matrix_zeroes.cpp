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