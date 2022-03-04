/*
973. K Closest Points to Origin
Medium

5045

201

Add to List

Share
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).



Example 1:


Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        // Brute force approach
        vector<vector<int>> op;
        map<vector<int>, double> m;
        vector<double> dist;
        // Mapping pairs with distance(doing so, because pair will be unique)
        for (int i = 0; i < points.size(); i++)
        {
            //  pair<int,int> p1={points[i][0],points[i][1]};
            vector<int> v(2, 0);
            v[0] = points[i][0];
            v[1] = points[i][1];
            double dis = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            // cout<<"dis of: "<<points[i][0]<<","<<points[i][1]<<" is: "<<dis<<endl;
            m[v] = dis;
            // Pushing this distance into distance array
            dist.push_back(dis);
        }
        // Sorting distance to have minimum distance at first
        sort(dist.begin(), dist.end());
        // for(auto e:dist) cout<<e<<" ";
        int i = 0;
        // Pushing elemets into op until required size by matchi ng distance from distance arr
        while (op.size() != k && i < dist.size())
        {
            for (auto e : m)
            {
                if (e.second == dist[i])
                    op.push_back(e.first);
            }
            i++;
        }
        return op;
    }
};