/*
Taking Graph as input using adjacency list

and dislaying all nodes adjacent to current nodes

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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
    return 0;
}