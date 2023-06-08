#include <bits/stdc++.h>
using namespace std;
bool DFS(int src, int parent, vector<int> adj[], vector<bool> &visited)
{
    visited[src] = true;

    for (int &u : adj[src])
    {
        if (visited[u] == false)
        {
            if (DFS(u, src, adj, visited))
                return true;
        }
        else if (u != parent)
            return true;
    }

    return false;
}

bool checkDFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i)
    {
        if (visited[i] == false)
        {
            if (DFS(i, -1, adj, visited))
                return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    return checkDFS(adj, V);
}
int main()
{
    int V = 4;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    cout << isCycle(V, adj);
}