#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<int> &op, vector<int> &vis, vector<int> adj[], int n)
{
    // Marking current node visited and pushing into op
    vis[n] = 1;
    op.push_back(n);
    // Visiting adjacent node of current node
    for (auto e : adj[n])
    {
        if (!vis[e])
        {
            dfs(op, vis, adj, e);
        }
    }
}
int main()
{
    int n, e; // nodes,edges

    // Taking number of nodes as input
    cout << "Enter number of nodes: ";
    cin >> n;

    // Taking number of edges as input
    cout << "Enter number of edges: ";
    cin >> e;
    vector<int> adj[n + 1];
    // Taking corresponding to number of edges, the node between which the edge exists
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cout << "Enter node and it's adjacent node: ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Displaying node and it's corresponding edges
    for (int i = 1; i <= n; i++)
    {
        cout << "Node is: " << i << " Adjacent nodes are: ";
        for (auto e : adj[i])
            cout << e << " ";
        cout << endl;
    }
    // Taking vis vector to avoiding visiting unvisited
    vector<int> vis(n + 1, 0);
    vector<int> op;

    // Visiting all un-visited nodes using dfs
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(op, vis, adj, i);
        }
    }
    // Displaying output
    for (auto e : op)
        cout << e << " ";
    return 0;
}
