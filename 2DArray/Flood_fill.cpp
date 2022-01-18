/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.

 

Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]
*/
#include <bits/stdc++.h>
using namespace std;
//BRUTE FORCE
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         int cols=image[0].size();
        int rows=image.size();
        //For keeping track of visited locations
        vector<vector<int>> v(rows,vector<int>(cols,0));
        queue<pair<int,int>> q;
       //Cannot start at index which does't exist
        if(sr>=rows || sc>=cols) return image;
        
        //Saving coor of starting index
        int color=image[sr][sc];
        //Making it colord different
        image[sr][sc]=newColor;
        //Marking it visited
        v[sr][sc]=1;
        
        //Pushing starting pair
        pair<int,int> p={sr,sc};
        q.push(p);
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            if(x-1>=0 && image[x-1][y]==color ){
                if(v[x-1][y]==0){
                     image[x-1][y]=newColor;
                     q.push({x-1,y});
                     v[x-1][y]=1;
                }
               
            }
            if(x+1<rows && image[x+1][y]==color){
                 if(v[x+1][y]==0){
                image[x+1][y]=newColor;
                q.push({x+1,y});
                     v[x+1][y]==1;
                 }
            }
            if(y-1>=0 && image[x][y-1]==color){
                   if(v[x][y-1]==0){
                image[x][y-1]=newColor;
                q.push({x,y-1});
                       v[x][y-1]==1;
                   }
            }
            if(y+1<cols && image[x][y+1]==color){
                    if(v[x][y+1]==0){
                image[x][y+1]=newColor;
                q.push({x,y+1});
                        v[x][y+1]==1;
                    }
            }
        }
        return image;
    }
};