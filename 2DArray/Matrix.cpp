/*
542. 01 Matrix
Medium

3941

191

Add to List

Share
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.



Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> op(rows, vector<int>(cols, 10000000));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j] == 0)
                {
                    op[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i - 1 >= 0)
                {
                    op[i][j] = min(op[i - 1][j] + 1, op[i][j]);
                }
                if (i + 1 < rows)
                {
                    op[i][j] = min(op[i + 1][j] + 1, op[i][j]);
                }
                if (j - 1 >= 0)
                {
                    op[i][j] = min(op[i][j - 1] + 1, op[i][j]);
                }
                if (j + 1 < cols)
                {
                    op[i][j] = min(op[i][j + 1] + 1, op[i][j]);
                }
            }
        }
        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 0; j--)
            {
                if (i - 1 >= 0)
                {
                    op[i][j] = min(op[i - 1][j] + 1, op[i][j]);
                }
                if (i + 1 < rows)
                {
                    op[i][j] = min(op[i + 1][j] + 1, op[i][j]);
                }
                if (j - 1 >= 0)
                {
                    op[i][j] = min(op[i][j - 1] + 1, op[i][j]);
                }
                if (j + 1 < cols)
                {
                    op[i][j] = min(op[i][j + 1] + 1, op[i][j]);
                }
            }
        }
        return op;
    }
};