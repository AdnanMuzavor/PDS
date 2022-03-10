/*
1559. Detect Cycles in 2D Grid
Medium

567

21

Add to List

Share
Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.



Example 1:



Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
Output: true
Explanation: There are two valid cycles shown in different colors in the image below:

Example 2:



Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
Output: true
Explanation: There is only one valid cycle highlighted in the image below:

Example 3:



Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
Output: false
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool iscycle(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &vis, int rows, int cols, pair<int, int> p)
    {
        // cout<<"i: "<<i<<" , j:"<<j<<endl;

        // Marking current index visited
        vis[i][j] = 1;
        // Getting char which should be same in cycle
        char currchar = grid[i][j];

        // Checking bottom
        if (i - 1 >= 0 && grid[i - 1][j] == currchar && !(p.first == i - 1 && p.second == j))
        {
            // if bottom part is visited already and as checked above it's not ame as prev, we rteurn true
            if (vis[i - 1][j] || iscycle(grid, i - 1, j, vis, rows, cols, {i, j}))
                return true;
        }
        // checking top
        if (i + 1 < rows && grid[i + 1][j] == currchar && !(p.first == i + 1 && p.second == j))
        {
            // if top part is visited already and as checked above it's not ame as prev, we rteurn true
            if (vis[i + 1][j] || iscycle(grid, i + 1, j, vis, rows, cols, {i, j}))
                return true;
        }
        // check left
        if (j - 1 >= 0 && grid[i][j - 1] == currchar && !(p.first == i && p.second == j - 1))
        {
            // if left part is visited already and as checked above it's not ame as prev, we rteurn true
            if (vis[i][j - 1] || iscycle(grid, i, j - 1, vis, rows, cols, {i, j}))
                return true;
        }
        // check right
        if (j + 1 < cols && grid[i][j + 1] == currchar && !(p.first == i && p.second == j + 1))
        {
            // if right part is visited already and as checked above it's not ame as prev, we rteurn true
            if (vis[i][j + 1] || iscycle(grid, i, j + 1, vis, rows, cols, {i, j}))
                return true;
        }

        return false;
    }
    bool containsCycle(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!vis[i][j])
                {
                    if (iscycle(grid, i, j, vis, rows, cols, {-1, -1}))
                        return true;
                }
            }
        }
        return false;
    }
};

// Optimised way ocf writing the solution
class Solution
{
public:
    bool iscycle(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &vis, int rows, int cols, pair<int, int> p)
    {
        // Marking as visisted
        vis[i][j] = 1;
        // Getting all 4 directions
        int direc[5] = {0, 1, 0, -1, 0};
        for (int d = 0; d < 4; d++)
        {
            // Getting current direction
            int a = direc[d] + i;
            int b = direc[d + 1] + j;
            // Checking if index found is valid
            // Checking if char is same as at i,j
            // Checking if index value is not equal to prev
            if (a >= 0 && a < rows && b >= 0 && b < cols && grid[a][b] == grid[i][j] && !(a == p.first && b == p.second))
            {
                // If it's visited and we are visiting again, return true
                // else call next same functiion for next indices a,b and set
                // prev to current {i,j}
                if (vis[a][b] || iscycle(grid, a, b, vis, rows, cols, {i, j}))
                {
                    return true;
                }
            }
        }

        return false;
    }
    bool containsCycle(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!vis[i][j])
                {
                    if (iscycle(grid, i, j, vis, rows, cols, {-1, -1}))
                        return true;
                }
            }
        }
        return false;
    }
};