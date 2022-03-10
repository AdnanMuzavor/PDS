/*
1905. Count Sub Islands
Medium

714

25

Add to List

Share
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.



Example 1:


Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
Example 2:


Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool process(vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<int>> &vis, int i, int j)
    {
        // For searching
        queue<pair<int, int>> q;
        // To push land cell indices of island
        vector<pair<int, int>> op;
        // If current land is water in grid1 means it's ecxtra and hence cannot be counted
        if (grid1[i][j] == 0)
            return false;
        vis[i][j] = 1;
        q.push({i, j});
        int rows = grid2.size();
        int cols = grid2[0].size();
        // Starting processing
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x - 1 >= 0 && grid2[x - 1][y] == 1 && vis[x - 1][y] == 0)
            {
                vis[x - 1][y] = 1;
                q.push({x - 1, y});
                // Pushing into op vector indices of this land cell
                op.push_back({x - 1, y});
            }
            if (y - 1 >= 0 && grid2[x][y - 1] == 1 && vis[x][y - 1] == 0)
            {
                vis[x][y - 1] = 1;
                q.push({x, y - 1});
                // Pushing into op vector indices of this land cell
                op.push_back({x, y - 1});
            }
            if (x + 1 < rows && grid2[x + 1][y] == 1 && vis[x + 1][y] == 0)
            {
                vis[x + 1][y] = 1;
                q.push({x + 1, y});
                // Pushing into op vector indices of this land cell
                op.push_back({x + 1, y});
            }
            if (y + 1 < cols && grid2[x][y + 1] == 1 && vis[x][y + 1] == 0)
            {
                vis[x][y + 1] = 1;
                q.push({x, y + 1});
                // Pushing into op vector indices of this land cell
                op.push_back({x, y + 1});
            }
        }
        // Traversing indices recorded in current island
        for (auto e : op)
        {
            int x = e.first;
            int y = e.second;
            // If any land cell is ectra means current island cannot be sub island
            // of island in grid 1
            if (grid1[x][y] == 0)
                return false;
        }
        return true;
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int ans = 0;
        // Getting rows and columns of grid2
        int rows = grid2.size();
        int cols = grid2[0].size();
        // Visisted vector to keep track of visited lands
        vector<vector<int>> vis(rows, (vector<int>(cols, 0)));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid2[i][j] == 1 && vis[i][j] == 0)
                {
                    // If island is subisland of island in grid1 returns true
                    if (process(grid1, grid2, vis, i, j))
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};