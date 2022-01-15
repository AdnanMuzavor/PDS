/*
240. Search a 2D Matrix II
Medium

6407

114

Add to List

Share
Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.


Example 1:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
Example 2:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // int cols=matrix[0].size();
        // int rows=matrix.size();
        //         if(target<matrix[0][0] || target>matrix[rows-1][cols-1]){
        //             return false;
        //         }

        //         int soln=cols-1;
        //         vector<int> v;
        //         for(int i=0;i<cols;i++){
        //             if(target>matrix[0][i]){
        //                 v.push_back(soln);
        //                 soln=i;

        //             }
        //             else if(target==matrix[0][i]){
        //                 return true;
        //             }
        //         }
        //         cout<<"soln:"<<soln<<endl;
        //         int i=0;

        //         while(i!=v.size()){
        //          soln=v[i];
        //             v.pop_back();
        //          i++;
        //        // cout<<"soln is : "<<soln<<endl;
        //         for(int i=0;i<rows;i++){
        //             if(matrix[i][soln]==target){
        //                 return true;
        //             }
        //         }
        //         }
        //         return false;

        // Starting from Either 15(Last colmn,first row) or
        // Starting from 18(first column,last row)
        int cols = matrix[0].size();
        int rows = matrix.size();
        int r = 0;
        int c = cols - 1;
        while (r < rows && c >= 0)
        {
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] > target)
            {
                c--;
            }
            else
            {
                r++;
            }
        }
        return false;
    }
};