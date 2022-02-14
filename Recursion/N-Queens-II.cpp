/*
52. N-Queens II
Hard

1534

208

Add to List

Share
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.



Example 1:


Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
Example 2:

Input: n = 1
Output: 1
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int col, vector<string> board, int &ans, int n, vector<int> leftrow, vector<int> upperdiag, vector<int> lowerdiag)
    {
        if (col == n)
        {
            ans++;
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (leftrow[row] == 0 && upperdiag[(n - 1) + col - row] == 0 && lowerdiag[row + col] == 0)
            {
                // If we enter in means this position can be allocated for queens
                board[row][col] = 'Q';
                leftrow[row] = 1;
                upperdiag[(n - 1) + (col - row)] = 1;
                lowerdiag[row + col] = 1;
                solve(col + 1, board, ans, n, leftrow, upperdiag, lowerdiag);
                // Once considering position removing it
                board[row][col] = '.';
                leftrow[row] = 0;
                upperdiag[(n - 1) + (col - row)] = 0;
                lowerdiag[row + col] = 0;
            }
        }
    }
    int totalNQueens(int n)
    {
        int ans = 0;
        vector<string> board(n, "");
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        vector<int> leftrow(n, 0);             // Checking if left row occupied
        vector<int> upperdiag((2 * n) - 1, 0); // Checling if upper diagonal occupied
        vector<int> lowerdiag((2 * n) - 1, 0); // Checking if lower diagonal occupied
        solve(0, board, ans, n, leftrow, upperdiag, lowerdiag);
        return ans;
    }
};