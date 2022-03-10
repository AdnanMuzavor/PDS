/*
785. Is Graph Bipartite?
Medium

3884

255

Add to List

Share
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.



Example 1:


Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
Example 2:


Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
*/
#include <bits/stdc++.h>
using namespace std;
// BRUTE FORCE PATTERN, BETTER PATTERN DOWN
//  TC: O(N+E)
//  SC: (N+E) ->ADJACENCY LIST, O(N) QUEUE, O(N) VISITED ARRAY
class Solution
{
public:
    bool BFS(vector<int> adj[], vector<int> &vis, int n)
    {
        vis[n] = 1;
        queue<pair<int, int>> q;
        // Coloring current node with 1
        q.push({n, 1});
        while (!q.empty())
        {
            // Hetting node value and color
            int node = q.front().first;
            int color = q.front().second;
            q.pop();
            // Checking for adjacents
            for (auto e : adj[node])
            {
                // If adjacent is visited and color is same return false
                if (vis[e] && vis[e] == color)
                    return false;
                // else if not visisted
                else if (!vis[e])
                {
                    // color with opposite color and push into queue
                    vis[e] = (color == 1 ? 2 : 1);
                    q.push({e, vis[e]});
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        // Getting number of nodes
        int n = graph.size();
        // Taking an adjacency list
        vector<int> adj[n + 1];
        // Putting elements in adjacency list
        int i = 0;
        for (auto v : graph)
        {
            int node = i;
            for (auto e : v)
            {
                adj[node].push_back(e);
            }
            i++;
        }
        // ADDITIONAL-PART
        // Displayi9ng graph as per adjacent nodes
        //         for(int i=0;i<graph.size();i++){
        //             cout<<"node is: "<<i<<endl;
        //             cout<<"Adjacent nodes are: ";
        //             for(auto e:adj[i]) cout<<e<<" ";
        //             cout<<endl;

        //         }
        // Vector visited to keep track of colors
        vector<int> vis(n + 1, 0);
        // Graph may present in componets hence checking for each component
        for (int i = 0; i < graph.size(); i++)
        {
            // Checking only for non-visited
            if (!vis[i])
            {
                // If one component returns true,other may return false so contiue
                if (BFS(adj, vis, i))
                    continue;
                else
                    return false;
            }
        }
        // If we reach her emeans no faklse, hence we return true
        return true;
    }
};

// BETTER PATTERN FOR SAME CODE
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            // if colored
            if (color[i])
                continue;
            // else color it
            color[i] = 1;
            q.push(i);
            // Visit it's adjacent
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                // Visiting adjacents
                for (auto e : graph[node])
                {
                    // If visisted and has same color as adjacent node return false
                    if (color[e] && color[e] == color[node])
                        return false;
                    // else if not colored,color it with color 2 and push in queue
                    else if (!color[e])
                    {
                        // coloring with opoiste color
                        color[e] = (color[node] == 1 ? 2 : 1);
                        q.push(e);
                    }
                }
            }
        }
        return true;
    }
};