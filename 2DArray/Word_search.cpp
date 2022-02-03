/*
79. Word Search
Medium

8306

312

Add to List

Share
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.



Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        //  Checking by starting from each of the indices
        for (unsigned int i = 0; i < board.size(); i++)
            for (unsigned int j = 0; j < board[0].size(); j++)
                if (dfs(board, i, j, word))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>> &board, int i, int j, string &word)
    {
        // Since we are removing one word each time it is found, there will be point where string size will be reduced to zero, hence since all chars in words were found, we return true
        if (!word.size())
            return true;
        // if we go outof bound or invase it's char we are loooking for is not there
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
            return false;

        // Current char is found so we save it in c
        char c = board[i][j];
        // and replace it with star to prevent reconsideration of traversed index
        board[i][j] = '*';
        // Removing first char from string being found
        string s = word.substr(1);
        cout << "searching s: " << s << endl;
        // Searching for next word ahead
        bool ret = dfs(board, i - 1, j, s) || dfs(board, i + 1, j, s) || dfs(board, i, j - 1, s) || dfs(board, i, j + 1, s);
        // once processing is done, we replace the orifinal char in board which we had replaced with star
        board[i][j] = c;
        return ret;
    }
};