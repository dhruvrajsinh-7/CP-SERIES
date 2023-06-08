#include <bits/stdc++.h>
using namespace std;
void dfs(int start, vector<bool> &vis, stack<int> &s, vector<int> adj[])
{
    vis[start] = 1;

    for (int nbr : adj[start])
    {
        if (!vis[nbr])
        {
            dfs(nbr, vis, s, adj);
        }
    }

    s.push(start);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<bool> vis(V);
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, s, adj);
        }
    }
    vector<int> res;
    for (int i = 0; i < V; i++)
    {
        res.push_back(s.top());
        s.pop();
    }
    return res;
}
int main()
{
    int V = 4;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    vector<int> res = topoSort(V, adj);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}