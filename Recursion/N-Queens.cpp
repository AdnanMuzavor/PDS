/*
51. N-Queens
Hard

5120

144

Add to List

Share
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.



Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
*/
#include <bits/stdc++.h>
using namespace std;

// Striver 's time complexity optimised solution
class Solution
{
public:
    void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n, vector<int> &leftrow, vector<int> &upperdiag, vector<int> &lowerdiag)
    {
        if (col == n)
        {
            // If we crosss the last column implies all columns are filled
            ans.push_back(board);
            return;
        }
        // else we'll go through each row and check if it's save to place queen,
        // we we place we'll be moving to next column
        for (int i = 0; i < n; i++)
        {
            // i -> rows
            // If row,upperdiag and lower diag are not occupied by queen then position is safe
            // 1->left row not occupied
            // 2->lower diagonal not occupied
            // 3->upper diagonal not occupied
            if (leftrow[i] == 0 && lowerdiag[i + col] == 0 && upperdiag[(n - 1) + (col - i)] == 0)
            {
                board[i][col] = 'Q';
                leftrow[i] = 1;                     // left row occupied
                lowerdiag[i + col] = 1;             // lower diagonal occupied
                upperdiag[(n - 1) + (col - i)] = 1; // upper diagonal occupied
                // After placing queen we'll xheck for next column
                solve(col + 1, ans, board, n, leftrow, upperdiag, lowerdiag);
                // After coming back to check for next rows we should remove queen
                board[i][col] = '.';
                leftrow[i] = 0;                     // left row unoccupied
                lowerdiag[i + col] = 0;             // lower diagonal unoccupied
                upperdiag[(n - 1) + (col - i)] = 0; // upper diagonal unoccupied
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        // Output vector which will contain vector mof strings;
        vector<vector<string>> ans;
        // Board will be a like a column such that each row has strings
        // Or you can think of it as row with cols
        vector<string> board(n, "");
        // You can imagien this
        //     ""
        //     ""
        //     ""
        //     ""
        string s(n, '.'); // . . . .
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        // This will form
        //    "...."
        //    "...."
        //    "...."
        //    "...."
        // Checking for row(i.e if same row is occupied)
        vector<int> row(n, 0);
        // Checking upper diagonal
        vector<int> upperdiag((2 * n) - 1, 0);
        // Checking for lower diagonal
        vector<int> lowerdiag((2 * n) - 1, 0);
        solve(0, ans, board, n, row, upperdiag, lowerdiag);
        return ans;
    }
};

// BRUTE FORCE
class Solution
{
public:
    bool issafe(int row, int col, vector<string> board, int n)
    {
        int r = row, c = col;
        // We know that only left side are filled so checking on left sides

        // Checking ipper left diagonal
        while (r >= 0 && c >= 0)
        {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        r = row, c = col;
        // Checking current row's left
        while (c >= 0)
        {
            if (board[r][c] == 'Q')
                return false;
            c--;
        }

        // Checking lower left disagonal
        r = row, c = col;
        while (r < n && c >= 0)
        {
            if (board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }

        // Else return true as position is safe;
        return true;
    }
    void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n)
    {
        if (col == n)
        {
            // If we crosss the last column implies all columns are filled
            ans.push_back(board);
            return;
        }
        // else we'll go through each row and check if it's save to place queen,
        // we we place we'll be moving to next column
        for (int i = 0; i < n; i++)
        {
            // i -> rows
            if (issafe(i, col, board, n))
            {
                board[i][col] = 'Q';
                // After placing queen we'll xheck for next column
                solve(col + 1, ans, board, n);
                // After coming back to check for next rows we should remove queen
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        // Output vector which will contain vector mof strings;
        vector<vector<string>> ans;
        // Board will be a like a column such that each row has strings
        // Or you can think of it as row with cols
        vector<string> board(n, "");
        // You can imagien this
        //     ""
        //     ""
        //     ""
        //     ""
        string s(n, '.'); // . . . .
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        // This will form
        //    "...."
        //    "...."
        //    "...."
        //    "...."
        solve(0, ans, board, n);
        return ans;
    }
};