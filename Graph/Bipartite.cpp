#include <bits/stdc++.h>
using namespace std;
bool DFSisBipartite(int node, vector<int> adj[], vector<bool> &visited, vector<int> &color)
{
    visited[node] = true;
    for (auto nbr : adj[node])
    {
        if (!visited[nbr])
        {
            color[nbr] = 1 - color[node];
            if (!DFSisBipartite(nbr, adj, visited, color))
                return false;
        }
        else
        {
            if (node != nbr && color[node] == color[nbr])
                return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<bool> visited(V, 0);
    vector<int> color(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (!DFSisBipartite(i, adj, visited, color))
                return false;
        }
    }
    return true;
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << isBipartite(V, adj);
    return 0;
}