/*
36. Valid Sudoku
Medium

4441

670

Add to List

Share
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.


Example 1:


Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isvalid(vector<vector<char>> board, int row, int col)
    {
        int c = board[row][col];
        for (int i = 0; i < 9; i++)
        {
            // Checking in row for similar element
            if (i != col && board[row][i] == c)
                return false;
            // Checking for column
            if (i != row && board[i][col] == c)
                return false;
            // Checking in 3*3 box
            int r1 = 3 * (row / 3) + (i / 3);
            int c1 = 3 * (col / 3) + (i % 3);
            // If it's current position,it should'nt be checked
            if ((r1 == row && c1 == col))
            {
                continue;
            }
            if (board[r1][c1] == c)
                return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int r = board.size();
        int c = board[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] != '.')
                {
                    if (isvalid(board, i, j) == false)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};