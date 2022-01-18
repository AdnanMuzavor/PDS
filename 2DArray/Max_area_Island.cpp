/*
695. Max Area of Island
Medium

5067

134

Add to List

Share
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.



Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthans(vector<vector<int>> &image, vector<vector<int>> &v, int sr, int sc, int newColor)
    {
        int cols = image[0].size();
        int rows = image.size();
        // For keeping track of visited locations

        queue<pair<int, int>> q;
        // Cannot start at index which does't exist
        if (sr >= rows || sc >= cols)
            return 0;

        // Saving coor of starting index
        int color = image[sr][sc];

        // Making it colord different
        image[sr][sc] = newColor;
        // Marking it visited
        v[sr][sc] = 1;

        // Pushing starting pair
        pair<int, int> p = {sr, sc};
        q.push(p);

        int l = 0;
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            l += 1;
            int x = p.first;
            int y = p.second;
            if (x - 1 >= 0 && image[x - 1][y] == color)
            {
                if (v[x - 1][y] == 0)
                {
                    image[x - 1][y] = newColor;
                    q.push({x - 1, y});
                    v[x - 1][y] = 1;
                }
            }
            if (x + 1 < rows && image[x + 1][y] == color)
            {
                if (v[x + 1][y] == 0)
                {
                    image[x + 1][y] = newColor;
                    q.push({x + 1, y});
                    v[x + 1][y] = 1;
                }
            }
            if (y - 1 >= 0 && image[x][y - 1] == color)
            {
                if (v[x][y - 1] == 0)
                {
                    image[x][y - 1] = newColor;
                    q.push({x, y - 1});
                    v[x][y - 1] = 1;
                }
            }
            if (y + 1 < cols && image[x][y + 1] == color)
            {
                if (v[x][y + 1] == 0)
                {
                    image[x][y + 1] = newColor;
                    q.push({x, y + 1});
                    v[x][y + 1] = 1;
                }
            }
        }
        return l;
    }
    int maxAreaOfIsland(vector<vector<int>> &image)
    {
        int cols = image[0].size();
        int rows = image.size();
        vector<vector<int>> v(rows, vector<int>(cols, 0));
        int l = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (image[i][j] == 1 && v[i][j] != 1)
                {
                    l = max(l, lengthans(image, v, i, j, 2));
                }
            }
        }
        return l;
    }
};