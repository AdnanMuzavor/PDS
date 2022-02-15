/*
37. Sudoku Solver
Hard

4583

144

Add to List

Share
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.



Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // We make it return bool so that if wrong char is placed we can immediately come back
    bool solve(vector<vector<char>> &board)
    {
        int r = board.size();
        int c = board[0].size();
        // Iterating through rows and columns
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                // If position is empty then only we shall try to include
                if (board[i][j] == '.')
                {
                    // We'll try for every char from '1'-'9'
                    for (char c = '1'; c <= '9'; c++)
                    {
                        // If it's valid to add at this position then only we shall add
                        if (isvalid(board, i, j, c))
                        {
                            board[i][j] = c; // adding char at this position as it's valid
                            // Afetr addding this position we'll try if we can fill other empty positions too, if possible we'll return true else we'll have to remove current filled char too as it's not allowing other apces to get filled
                            if (solve(board) == true)
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.'; // If char filled was invalid, removing that chr
                            }
                        }
                    }
                    // If we are unable to insert any character ,this im[plies that eleement previosly in serted was inserted at wrong position hence we return false
                    return false;
                }
            }
        }
        // If we reach here without returning false means all empty positions are filled and we can go back
        return true;
    }

    // Function to validate positions
    bool isvalid(vector<vector<char>> board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            // Checking for full row
            if (board[row][i] == c)
                return false;
            // Checking for column
            if (board[i][col] == c)
                return false;
            // Checking 3*3 board/Intuition on book
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
                return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        // Calling recursive soln to solve sudoku
        solve(board);
    }
};