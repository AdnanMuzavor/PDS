/*
74. Search a 2D Matrix
Medium

5592

239

Add to List

Share
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.


Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (target < matrix[0][0])
            return false;

        int cols = matrix[0].size();
        int rows = matrix.size();
        // If value < first ele or > last element
        if (target > matrix[rows - 1][cols - 1])
        {
            return false;
        }
        cout << rows << " " << cols << endl;
        // Setting soln row to last row
        int soln = rows - 1;
        for (int i = 1; i < rows; i++)
        {
            cout << "checling: " << matrix[i][0] << endl;
            // If ele to be found is < curr rows first elemet soln
            // row is row above it else by default it'll be last row
            if (target < matrix[i][0])
            {
                soln = i - 1;
                break;
            }
            // If by any chance we are able to find an element we can deal with it here itself
            else if (target == matrix[i][0] || target == matrix[i][cols - 1])
            {
                return true;
            }
            // else if(target>matrix[i][cols-1]){
            //     soln=i+1;
            //     break;
            // }
        }
        // Searching in row where ans is expected to be found
        cout << "soln: mat is: " << soln << endl;
        for (int i = 0; i < cols; i++)
        {
            if (matrix[soln][i] == target)
            {
                return true;
            }
        }
        return false;
    }
};