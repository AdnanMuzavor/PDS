/*
797. All Paths From Source to Target
Medium

3802

112

Add to List

Share
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).



Example 1:


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Example 2:


Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// With adjacency list(not needed aqctually)
class Solution
{
public:
    void dfs(vector<vector<int>> &op, vector<int> curr, int n, int node, vector<int> adj[])
    {
        // If node for which we are processing is last node
        // means we have got path so we push into array and stop
        if (node == n)
        {

            op.push_back(curr);
            return;
        }

        // else we go to next adjacenyt node
        for (auto e : adj[node])
        {
            // Add it in path and visit it's adjacent further
            curr.push_back(e);
            dfs(op, curr, n, e, adj);
            // As we come back we pop it out to follow up next path
            curr.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int n = graph.size() - 1;
        // Making an adjacency list
        vector<int> adj[n + 1];
        for (int i = 0; i <= n; i++)
        {
            for (auto e : graph[i])
            {
                adj[i].push_back(e);
            }
        }
        // Displaying adjacency list
        //  for(int i=0;i<=n;i++){
        //      cout<<"node is: "<<i<<endl;
        //      cout<<"Adjacent nodes are: ";
        //      for(auto e:adj[i]) cout<<e<<" ";
        //      cout<<endl;
        //  }
        // For keeping track of output
        vector<vector<int>> op;
        // For current path which starts from 0
        vector<int> curr;
        curr.push_back(0);
        // dfs traversal
        dfs(op, curr, n, 0, adj);
        return op;
    }
};
// Without adjacency list
class Solution
{
public:
    void dfs(vector<vector<int>> &op, vector<int> curr, int n, int node, vector<vector<int>> &graph)
    {
        // If node for which we are processing is last node
        // means we have got path so we push into array and stop
        if (node == n)
        {

            op.push_back(curr);
            return;
        }

        // else we go to next adjacenyt node
        for (auto e : graph[node])
        {
            // Add it in path and visit it's adjacent further
            curr.push_back(e);
            dfs(op, curr, n, e, graph);
            // As we come back we pop it out to follow up next path
            curr.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int n = graph.size() - 1;
        // For keeping track of output
        vector<vector<int>> op;
        // For current path which starts from 0
        vector<int> curr;
        curr.push_back(0);
        // dfs traversal
        dfs(op, curr, n, 0, graph);
        return op;
    }
};