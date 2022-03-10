/*
1091. Shortest Path in Binary Matrix
Medium

2294

120

Add to List

Share
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.



Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
*/

#include <bits/stdc++.h>
using namespace std;

//  BRUTE FORCE O(N^2)
class Solution
{
public:
    int ans = INT_MAX;
    void recur(int i, int j, vector<vector<int>> grid, vector<vector<int>> &vis, int dis, int n, int val)
    {
        // If we reach to end of matrix we update distance
        if (i == n - 1 && j == n - 1)
        {
            ans = min(ans, dis);
            return;
        }
        // Visiting all 4 directions
        int direct[5] = {0, 1, 0, -1, 0};
        for (int d = 0; d < 4; d++)
        {
            int a = direct[d] + i;
            int b = direct[d + 1] + j;
            // Going ahead with direction only if possible
            if (a >= 0 && a < n && b >= 0 && b < n && grid[a][b] == val && !vis[a][b])
            {
                vis[a][b] = 1;
                recur(a, b, grid, vis, dis + 1, n, val);
                // Marking as unvisited after coming again as it acn be used for other path
                vis[a][b] = 0;
            }
        }
        // Visiting all 4 diagonal directions
        int diag[5] = {1, 1, -1, -1, 1};
        for (int d = 0; d < 4; d++)
        {
            int a = diag[d] + i;
            int b = diag[d + 1] + j;
            // Going ahead with direction only if possible
            if (a >= 0 && a < n && b >= 0 && b < n && grid[a][b] == val && !vis[a][b])
            {
                vis[a][b] = 1;
                recur(a, b, grid, vis, dis + 1, n, val);
                // Marking as unvisited after coming again as it acn be used for other path
                vis[a][b] = 0;
            }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int start = grid[0][0];
        // Handling base case
        int last = grid[rows - 1][cols - 1];
        // If start or last is not 0
        if (start != 0 || last != 0)
            return -1;
        if (start != last)
            return -1;
        // Using visited vectors
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        recur(0, 0, grid, vis, 1, rows, 0);
        // If ans is not INT_MAX means path to last is not possible so we return -1
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};

// USING BFS
// Diff->Here we saving distance/steps required upto that grid hence we can avoid repetition of procedure
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {

        int rows = grid.size();
        int cols = grid[0].size();
        // If first or last index val is 1
        if (grid[rows - 1][cols - 1] == 1 || grid[0][0] == 1)
            return -1;
        // Getting corrdinates
        int x_cor[8] = {0, 1, 0, -1, 1, 1, -1, -1};
        int y_cor[8] = {1, 0, -1, 0, 1, -1, -1, 1};
        // Pushing first value and marking it's val as 1,(as 1st step is taken)
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty() && !grid[rows - 1][cols - 1])
        {
            // Getting coordinates
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                // Visiting all 8 directions
                int a = x + x_cor[i];
                int b = y + y_cor[i];
                if (a >= 0 && a < rows && b >= 0 && b < cols && grid[a][b] == 0)
                {
                    // Saving stesp for each direction
                    grid[a][b] = grid[x][y] + 1;
                    q.push({a, b});
                }
            }
        }
        // AT last we'll auto matically have minimum difference
        if (grid[rows - 1][cols - 1] != 0)
            return grid[rows - 1][cols - 1];
        return -1;
    }
};