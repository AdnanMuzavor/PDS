/*
Rat in a Maze Problem - I
Medium Accuracy: 37.73% Submissions: 100k+ Points: 4
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at
(3, 3) from (0, 0) by two paths - DRDDRR
and DDRDRR, when printed in sorted order
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is
blocked.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //->Without visiting matrix it doesnyt work because example
    // at index [1][0]=1 so i move down, then in one case i'll move to right
    // In  other i can move to bottom which is valid
    // But I can also move back up ,if I do so ill keep on fluctuating between these two
    // For inifinite number of times hence to prevent it we are keeping track of visisted
    // positions and once we visit and come back we make them back 0
    vector<string> op;
    void recurr(int i, int j, string res, vector<vector<int>> m, int n, vector<vector<int>> &vis)
    {
        //   cout<<"at : "<<i<<" , "<<j<<endl;
        if (i == n - 1 && j == n - 1)
        {
            op.push_back(res);
            return;
        }
        // Move down
        if (i + 1 < n && m[i + 1][j] == 1 && !vis[i + 1][j])
        {
            vis[i][j] = 1;
            recurr(i + 1, j, res + "D", m, n, vis);
            vis[i][j] = 0;
        }
        // Move up
        if (i - 1 >= 0 && m[i - 1][j] == 1 && !vis[i - 1][j])
        {
            vis[i][j] = 1;
            recurr(i - 1, j, res + "U", m, n, vis);
            vis[i][j] = 0;
        }
        // Move right
        if (j + 1 < n && m[i][j + 1] == 1 && !vis[i][j + 1])
        {
            vis[i][j] = 1;
            recurr(i, j + 1, res + "R", m, n, vis);
            vis[i][j] = 0;
        }
        // Move left
        if (j - 1 >= 0 && m[i][j - 1] == 1 && !vis[i][j - 1])
        {
            vis[i][j] = 1;
            recurr(i, j - 1, res + "L", m, n, vis);
            vis[i][j] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        int rows = m.size();
        int cols = m[0].size();
        // If matirx doesnt has valid end or valid starting point
        if (m[n - 1][n - 1] == 0 || m[0][0] == 0)
            return op;
        string res = "";
        vector<vector<int>> vis(n, vector<int>(n, 0));
        recurr(0, 0, res, m, n, vis);
        return op;
    }
};

// Reducing long code

class Solution
{
public:
    //->Without visiting matrix it doesnyt work because example
    // at index [1][0]=1 so i move down, then in one case i'll move to right
    // In  other i can move to bottom which is valid
    // But I can also move back up ,if I do so ill keep on fluctuating between these two
    // For inifinite number of times hence to prevent it we are keeping track of visisted
    // positions and once we visit and come back we make them back 0
    vector<string> op;
    // For iterating wrt i
    int arri[4] = {1, 0, 0, -1};
    int arrj[4] = {0, 1, -1, 0};

    void recurr(int i, int j, string res, vector<vector<int>> m, int n, vector<vector<int>> &vis)
    {
        //   cout<<"at : "<<i<<" , "<<j<<endl;
        if (i == n - 1 && j == n - 1)
        {
            op.push_back(res);
            return;
        }

        string direct = "DRLU";
        for (int index = 0; index < 4; index++)
        {
            int nexti = i + arri[index];
            int nextj = j + arrj[index];
            if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < n && !vis[nexti][nextj] && m[nexti][nextj] == 1)
            {
                vis[i][j] = 1;
                recurr(nexti, nextj, res + direct[index], m, n, vis);
                vis[i][j] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        int rows = m.size();
        int cols = m[0].size();
        // If matirx doesnt has valid end or valid starting point
        if (m[n - 1][n - 1] == 0 || m[0][0] == 0)
            return op;
        string res = "";
        vector<vector<int>> vis(n, vector<int>(n, 0));
        recurr(0, 0, res, m, n, vis);
        return op;
    }
};
