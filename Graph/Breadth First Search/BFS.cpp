/*
BFS trversal using STRIVER's sheet

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> dfsfn(vector<int> adj[], int n)
{
    cout << "Inside fn" << endl;
    vector<int> vis(n + 1, 0);
    vector<int> dfs;
    for (int i = 1; i <= n; i++)
    {
        // Visiting node only if not visisted
        if (!vis[i])
        {
            vis[i] = 1;
            queue<int> q;
            q.push(i);
            // Visisting adjacent nodes of node pushed previously
            while (!q.empty())
            {
                int node = q.front();
                cout << " node : " << node << endl;
                // Pushing node in traversal
                dfs.push_back(node);
                q.pop();
                // Visiting adjacent node of pushed node
                for (auto e : adj[node])
                {
                    // Further visiting them only if not visited
                    if (!vis[e])
                    {
                        vis[e] = 1;
                        q.push(e);
                    }
                }
            }
        }
    }
    return dfs;
}
int main()
{
    int n; // Number of nodes
    int e; // Number of edges
    cout << "Enter no of nodes: ";
    cin >> n;
    cout << "Enter no of edges: ";
    cin >> e;
    // Declaring array of type vectors of size n+1
    vector<int> adj[n + 1];

    // Input is taken edges number of times as that many edges exists
    for (int i = 1; i <= e; i++)
    {
        // We need to take nodes adjacent to each nodes
        // If 2 is adjacent to 1
        // adj[1].push_back(2) and so on
        int node, adj_node;
        cin >> node;
        cin >> adj_node;
        adj[node].push_back(adj_node);
        // Since graph is undirected that means:
        // if 2 is adjacent to 1
        // so 1 is adjacent to 2
        adj[adj_node].push_back(node);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "node: " << i;
        cout << "\tAdjacent values: ";
        for (auto e : adj[i])
            cout << e << " ";
        cout << endl;
    }

    vector<int> dfs = dfsfn(adj, n);
    for (auto e : dfs)
        cout << e << " ";
    return 0;
}