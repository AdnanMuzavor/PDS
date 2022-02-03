/*
212. Word Search II
Hard

5417

188

Add to List

Share
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.



Example 1:


Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
Example 2:


Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
*/
#include <bits/stdc++.h>
using namespace std;

//BRUTE FORCE APPROACH
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

        // Searching for next word ahead
        bool ret = dfs(board, i - 1, j, s) || dfs(board, i + 1, j, s) || dfs(board, i, j - 1, s) || dfs(board, i, j + 1, s);
        // once processing is done, we replace the orifinal char in board which we had replaced with star
        board[i][j] = c;
        return ret;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> op;

        for (auto e : words)
        {
            if (exist(board, e))
                op.push_back(e);
        }
        return op;
    }
};