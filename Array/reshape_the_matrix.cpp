/*
In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.



Example 1:


Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]
Example 2:


Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        vector<vector<int>> op;
        int cols = mat[0].size();
        int rows = mat.size();
        int total = rows * cols;
        cout << cols << " " << rows << " Total: " << rows * cols << endl;
        if (r * c == total)
        {
            vector<int> v;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    v.push_back(mat[i][j]);
                }
            }
            vector<int> soln;
            int c1 = c, r1 = r;
            for (int i = 0; i < v.size(); i++)
            {

                soln.push_back(v[i]);
                c1--;
                if (c1 == 0)
                {
                    op.push_back(soln);
                    soln.clear();
                    c1 = c;
                    r1--;
                }
            }
        }
        else
        {
            return mat;
        }
        return op;
    }
};
