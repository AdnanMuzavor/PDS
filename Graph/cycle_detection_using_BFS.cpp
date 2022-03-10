#include <iostream>

#include <bits/stdc++.h>
using namespace std;
bool iscycleBFS(int i, int n, vector<int> &vis, vector<int> adj[])
{
    vis[i] = 1;
    // Making a queue to record current and it's prev
    queue<pair<int, int>> q;
    // Since starting from i,  pushing it's prev as -1
    q.push({i, -1});
    // Trvasering it's adjacents
    while (!q.empty())
    {
        int node = q.front().first;
        int prev = q.front().second;
        q.pop();
        for (auto e : adj[node])
        {
            if (vis[e] == 0)
            {
                // Marking visited
                vis[e] = 1;
                // Pushing into queue this adjavent node and it'sprebv val being node
                q.push({e, node});
                // cout
                cout << "Pushing: " << e << " , " << node << endl;
            }
            else
            {
                // Means it's visited
                // Since visisted checking if it's not equal to prev as it diesn't means cycle
                if (e != prev)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<int> adj[n + 1];
    for (int i = 1; i <= e; i++)
    {
        int p, q;
        cout << "Enter node val: ";
        cin >> p;
        cout << "Enter adjacent node value: ";
        cin >> q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    // Visisted vector to keep track of Visisted
    vector<int> vis(n + 1, 0);
    int flag = 0;
    // Traversing al components and running is cycle fn on them
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            // If cyucle found loop will break
            if (iscycleBFS(i, n, vis, adj))
            {
                cout << "Cycle detected" << endl;
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
        cout << "Cycle not detected" << endl;
    return 0;
}