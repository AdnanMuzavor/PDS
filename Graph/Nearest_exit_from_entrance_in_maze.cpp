/*
1926. Nearest Exit from Entrance in Maze
Medium

381

18

Add to List

Share
You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.



Example 1:


Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
Output: 1
Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.
Example 2:


Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
Output: 2
Explanation: There is 1 exit in this maze at [1,2].
[1,0] does not count as an exit since it is the entrance cell.
Initially, you are at the entrance cell [1,0].
- You can reach [1,2] by moving 2 steps right.
Thus, the nearest exit is [1,2], which is 2 steps away.
Example 3:


Input: maze = [[".","+"]], entrance = [0,0]
Output: -1
Explanation: There are no exits in this maze.
*/
#include <bits/stdc++.h>
using namespace std;

// Worked for around 94 text cases
class Solution
{
public:
    int ans = INT_MAX;
    int iscorner(int i, int j, int rows, int cols)
    {
        if (i == 0)
            return 1;
        if (j == 0)
            return 1;
        if (i == rows - 1)
            return 1;
        if (j == cols - 1)
            return 1;
        return 0;
    }
    void dfs(int i, int j, int dis, vector<vector<int>> &vis, vector<vector<char>> grid, int x, int y)
    {
        // cout<<"dis is: "<<dis<<endl;
        // cout<<"inside: i: "<<i<<" j: "<<j<<endl;
        if (i == x && j == y)
        {
            cout << "Yes" << endl;
            ans = min(ans, dis);
            return;
        }
        vis[i][j] = 1;
        if (i - 1 >= 0 && !vis[i - 1][j] && grid[i - 1][j] == '.')
        {

            dfs(i - 1, j, dis + 1, vis, grid, x, y);
        }
        if (i + 1 < grid.size() && !vis[i + 1][j] && grid[i + 1][j] == '.')
        {

            dfs(i + 1, j, dis + 1, vis, grid, x, y);
        }
        if (j - 1 >= 0 && !vis[i][j - 1] && grid[i][j - 1] == '.')
        {

            dfs(i, j - 1, dis + 1, vis, grid, x, y);
        }
        if (j + 1 < grid[0].size() && !vis[i][j + 1] && grid[i][j + 1] == '.')
        {

            dfs(i, j + 1, dis + 1, vis, grid, x, y);
        }
    }
    int nearestExit(vector<vector<char>> &grid, vector<int> &entrance)
    {
        int x = entrance[0];
        int y = entrance[1];
        // cout<<"x: "<<x<<" , y:"<<y<<endl;

        vector<pair<int, int>> exits;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (iscorner(i, j, rows, cols))
                {
                    if (grid[i][j] == '.' && !(i == x && j == y))
                    {
                        cout << "Entrace chosen: " << i << " , " << j << endl;
                        // cout<<" i: "<<i<<" j: "<<j<<endl;
                        vector<vector<int>> vis(rows, vector<int>(cols, 0));
                        dfs(i, j, 0, vis, grid, x, y);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

// USING BFS

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int direct[5] = {0, 1, 0, -1, 0};
        // Getting size
        int rows = maze.size();
        int cols = maze[0].size();
        // Getting coordinates
        int x = entrance[0];
        int y = entrance[1];
        // We''ll use same grid to makr as visited i.e ones we visit call
        //, we'll make that char "."
        int moves = 1;
        // Since starting from x,y making it visisted and pushing into queue
        queue<pair<int, int>> q;
        q.push({x, y});
        maze[x][y] = '+';
        while (!q.empty())
        {
            int l = q.size();
            while (l--)
            {
                // Getting the index
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                // From this index visiting all posible adj directions
                for (int d = 0; d < 4; d++)
                {
                    int x1 = a + direct[d];
                    int y1 = b + direct[d + 1];
                    // Validating x1,y1
                    if (x1 < 0 || x1 >= rows || y1 < 0 || y1 >= cols || maze[x1][y1] == '+')
                    {
                        continue;
                    }
                    // If valid and we are at border we can return moves
                    if (x1 == 0 || y1 == 0 || x1 == rows - 1 || y1 == cols - 1)
                        return moves;

                    maze[x1][y1] = '+'; // Marking index visited
                    q.push({x1, y1});   // Pushing into the queue
                }
            }
            moves++;
        }
        return -1;
    }
};