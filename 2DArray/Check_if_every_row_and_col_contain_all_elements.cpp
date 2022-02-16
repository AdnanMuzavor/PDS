/*
2133. Check if Every Row and Column Contains All Numbers
Easy

234

13

Add to List

Share
An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).

Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.



Example 1:


Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
Output: true
Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
Hence, we return true.
Example 2:


Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
Output: false
Explanation: In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
Hence, we return false.

*/
#include <bits/stdc++.h>
using namespace std;
// BRUTE FORCE

class Solution
{
public:
    bool isvalid(vector<vector<int>> m, int row, int col)
    {
        int e = m[row][col];
        for (int i = 0; i < m.size(); i++)
        {
            // Checking row if same element is repeating
            if (i != col && m[row][i] == e)
            {
                // cout<<"i : "<<i<<" row: "<<row<<" m[row][i] : "<<m[row][i]<<endl;
                return false;
            }
            // Checking column
            if (i != row && m[i][col] == e)
            {
                // cout<<"i : "<<i<<" col: "<<col<<" m[col][i] : "<<m[i][col]<<endl;
                return false;
            }
        }
        return true;
    }
    bool checkValid(vector<vector<int>> &matrix)
    {
        int n = matrix[0].size();

        // If n=1, elements are 1,2,3
        /// Same as sudoku solver that is we should just check that same element is not repeated more then omnce in row/column
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isvalid(matrix, i, j) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// OPTIMISED
class Solution
{
public:
    bool checkValid(vector<vector<int>> &matrix)
    {
        unordered_map<int, int> m;
        for (int i = 1; i <= matrix.size(); i++)
        {
            m[i] = 0;
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            // Validating rows
            for (int j = 0; j < matrix.size(); j++)
            {
                if (m[matrix[i][j]] != 0)
                    return false;
                else
                    m[matrix[i][j]] = 1;
            }
            // Resetting hashmap
            for (int k = 1; k <= matrix.size(); k++)
            {
                m[k] = 0;
            }
            // Validating columns
            for (int j = 0; j < matrix.size(); j++)
            {
                if (m[matrix[j][i]] != 0)
                    return false;
                else
                    m[matrix[j][i]] = 1;
            }
            // Resetting hashmap
            for (int k = 1; k <= matrix.size(); k++)
            {
                m[k] = 0;
            }
        }
        return true;
    }
};