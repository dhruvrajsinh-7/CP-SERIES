#include <bits/stdc++.h>
using namespace std;
bool dfs(int V, vector<int> adj[], vector<bool> &visited, vector<bool> &recstack, int i)
{
    visited[i] = true;
    recstack[i] = true;
    for (auto &e : adj[i])
    {
        if (visited[e] == false && dfs(V, adj, visited, recstack, e))
        {
            return true;
        }
        else if (recstack[e] == true)
        {
            return true;
        }
    }
    recstack[i] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<bool> recstack(V, false);
    bool isCyclic = false;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            isCyclic = dfs(V, adj, visited, recstack, i);
        }
        if (isCyclic)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int V = 4;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    cout << isCyclic(V, adj);
}