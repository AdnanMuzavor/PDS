/*
463. Island Perimeter
Easy

4131

227

Add to List

Share
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.



Example 1:


Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
Example 2:

Input: grid = [[1]]
Output: 4
Example 3:

Input: grid = [[1,0]]
Output: 4
*/
#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE USING EXTRA SPACE O(N^2)+O(L) L->LANDS
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        // Base case, only one cell exists
        // If it's land
        if (rows == 1 && cols == 1 && grid[0][0] == 1)
            return 4;

        // if it's water
        if (rows == 1 && cols == 1 && grid[0][0] == 0)
            return 0;

        // Array for keeping track of visisted lands
        vector<vector<int>> vis(rows, (vector<int>(cols, 0)));

        // queue will help in visiting surrounding cells
        queue<pair<int, int>> q;
        // Getting first cell
        int flag = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                    flag = 1;
                    break;
                }
            }
            // Breaking bouter loop as well on finding point
            if (flag == 1)
                break;
        }
        int ans = 0;
        // Visiting current land and checking it's surrounding
        while (!q.empty())
        {
            // Getting cell which was land
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            // Around this cell we'll have previosly visisted land
            // so this var keeps track of them
            int visited_lands = 0;
            // Since we have taken a cell we add it's parameter 4 into ans
            ans += 4;
            int q_prev_size = q.size();
            // If surrounded cells if land
            if (x - 1 >= 0 && grid[x - 1][y] == 1)
            {
                // Pushing into queue 0nly if not visited
                if (vis[x - 1][y] == 0)
                {
                    q.push({x - 1, y});
                    vis[x - 1][y] = 1;
                }
                // If visisted thn tHat edge which is connecting it should be removed
                // decreasin g parameter by 1 so we add it into visited_lands
                else
                {
                    visited_lands += 1;
                }
            }
            if (y - 1 >= 0 && grid[x][y - 1] == 1)
            {
                if (vis[x][y - 1] == 0)
                {
                    q.push({x, y - 1});
                    vis[x][y - 1] = 1;
                }
                else
                {
                    visited_lands += 1;
                }
            }
            if (y + 1 < cols && grid[x][y + 1] == 1)
            {
                if (vis[x][y + 1] == 0)
                {
                    q.push({x, y + 1});
                    vis[x][y + 1] = 1;
                }
                else
                {
                    visited_lands += 1;
                }
            }
            if (x + 1 < rows && grid[x + 1][y] == 1)
            {
                if (vis[x + 1][y] == 0)
                {
                    q.push({x + 1, y});
                    vis[x + 1][y] = 1;
                }
                else
                {
                    visited_lands += 1;
                }
            }

            // q.size() means q current size including those we added just now
            // So we subtract q current size from q prev size to get lands around current land
            // hence those many edges will gte deducted
            ans -= (q.size() - q_prev_size);
            // Again if around ther eis any land( basically a land from/through which we landed             //on current land), we subtract edge corrresponding to that land too.
            ans -= visited_lands;
        }
        return ans;
    }
};

// OPTIMISED SOLUTION

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int directions[5] = {0, 1, 0, -1, 0};
        int ans = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // skip if water
                if (grid[i][j] == 0)
                    continue;
                // If not add it's 4 edges into perimeter
                ans += 4;
                // Now as you find cells around subtract edges
                for (int k = 0; k < 4; k++)
                {
                    // Getting surrounding cell
                    int curr_row = i + directions[k];
                    int curr_col = j + directions[k + 1];
                    // if indexes are out of bounds or represent water thn deducting them
                    if (curr_row >= rows || curr_col >= cols || curr_row < 0 || curr_col < 0 || grid[curr_row][curr_col] == 0)
                        continue;
                    // else  it means we found 1 land around so we remove edge corresponding to it
                    ans--;
                }
            }
        }
        return ans;
    }
};