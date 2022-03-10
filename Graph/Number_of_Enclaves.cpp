/*1020. Number of Enclaves
Medium

1025

30

Add to List

Share
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.



Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
*/
#include <bits/stdc++.h>
using namespace std;
// Time 0(R+C) and Space(R*C)
class Solution
{
public:
    void makevis(vector<vector<int>> &vis, vector<vector<int>> &grid, int i, int j, int rows, int cols)
    {
        // Got an outer boundary as land so visiting lands possible from it
        // Marking them visisted
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x - 1 >= 0 && !vis[x - 1][y] && grid[x - 1][y] == 1)
            {
                vis[x - 1][y] = 1;
                q.push({x - 1, y});
            }
            if (x + 1 < rows && !vis[x + 1][y] && grid[x + 1][y] == 1)
            {
                vis[x + 1][y] = 1;
                q.push({x + 1, y});
            }
            if (y - 1 >= 0 && !vis[x][y - 1] && grid[x][y - 1] == 1)
            {
                vis[x][y - 1] = 1;
                q.push({x, y - 1});
            }
            if (y + 1 < cols && !vis[x][y + 1] && grid[x][y + 1] == 1)
            {
                vis[x][y + 1] = 1;
                q.push({x, y + 1});
            }
        }
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        // Intuition is to start from border and see
        // from each border point what all internal lands can be visited
        // Visited lands will have value=1, rest will have value =0
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        int ans = 0;
        // Vsiting first row
        for (int i = 0; i < cols; i++)
        {
            // If elememt was not visited and is 1 i.e land
            if (vis[0][i] == 0 && grid[0][i] == 1)
            {
                cout << "visiting: " << 0 << " , " << i << endl;
                makevis(vis, grid, 0, i, rows, cols);
            }
        }
        // Visiting last row
        for (int i = 0; i < cols; i++)
        {

            // If elememt was not visited and is 1 i.e land
            if (!vis[rows - 1][i] && grid[rows - 1][i] == 1)
            {
                cout << "visiting: " << rows - 1 << " , " << i << endl;
                makevis(vis, grid, rows - 1, i, rows, cols);
            }
        }
        // Visiting first column
        for (int i = 0; i < rows; i++)
        {
            if (!vis[i][0] && grid[i][0] == 1)
            {
                cout << "visiting: " << i << " , " << 0 << endl;
                makevis(vis, grid, i, 0, rows, cols);
            }
        }
        // Visiting last column
        for (int i = 0; i < rows; i++)
        {
            if (!vis[i][cols - 1] && grid[i][cols - 1] == 1)
            {
                cout << "visiting: " << i << " , " << cols - 1 << endl;
                makevis(vis, grid, i, cols - 1, rows, cols);
            }
        }
        // Going through visisted matrix to se which one is not visisted
        // Starting specifically from internal group and excluding outer rows and columns
        // FOr checking as theyll be definitely 1 if lands
        for (int i = 1; i < rows - 1; i++)
        {
            for (int j = 1; j < cols - 1; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                    ans++;
            }
        }
        return ans;
    }
};