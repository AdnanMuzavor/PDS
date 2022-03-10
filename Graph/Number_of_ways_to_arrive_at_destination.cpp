/*
1976. Number of Ways to Arrive at Destination
Medium

723

22

Add to List

Share
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.



Example 1:


Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
Example 2:

Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
*/

#include <bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution
{
public:
    int minval = INT_MAX;
    // To map distance with nodes
    unordered_map<int, int> m;
    void dfs(vector<int> adj[], int n, int node, int dist, map<pair<int, int>, int> disvals, vector<int> vis)
    {
        // if nod eis last value means we have reached at last node
        // So we push result and stop
        if (node == n)
        {
            m[dist]++;
            minval = min(minval, dist);
            return;
        }
        // Elese we mark current node as visited
        vis[node] = 1;

        // We traverse all it's adjacent if not included
        for (auto e : adj[node])
        {
            if (!vis[e])
            {
                // We add the distance as we have used an edge with that distance
                dfs(adj, n, e, dist + disvals[{node, e}], disvals, vis);
            }
        }
    }

    int countPaths(int n, vector<vector<int>> &roads)
    {

        // Create an adjacency list
        vector<int> adj[n];
        // Maintaing distanec between nodes
        map<pair<int, int>, int> telldist;
        for (auto e : roads)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            // Mapping distances
            telldist[{u, v}] = e[2];
            telldist[{v, u}] = e[2];
        }
        // for(int i=0;i<n;i++){
        //     cout<<"Node is: "<<i<<endl;
        //     cout<<"Adjacent is: ";
        //     for(auto e:adj[i]){
        //         cout<<e<<" at distance of: "<<telldist[{i,e}]<<endl;
        //     }
        //     cout<<endl;
        // }
        // vector visisted to keep track of visited
        vector<int> vis(n);
        // processing under dfs
        dfs(adj, n - 1, 0, 0, telldist, vis);
        return m[minval];
    }
};