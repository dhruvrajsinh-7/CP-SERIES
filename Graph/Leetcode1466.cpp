#include <bits/stdc++.h>
using namespace std;
int minReorder(int n, vector<vector<int>> &connections)
{
    int count = 0;
    vector<vector<pair<int, int>>> adj(n);
    for (vector<int> data : connections)
    {
        adj[data[0]].push_back({data[1], 1});
        adj[data[1]].push_back({data[0], -1});
    }
    vector<bool> vis(n, false);
    dfs(adj, 0, vis, count);
    return count;
}
void dfs(vector<vector<pair<int, int>>> &adj, int src, vector<bool> &vis, int count)
{
    if (vis[src])
    {
        return;
    }
    vis[src] = true;
    for (auto it : adj[src])
    {
        if (it.second == 1 && !vis[it.first])
        {
            count++;
        }
        dfs(adj, it.first, vis, count);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> connections(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> connections[i][0] >> connections[i][1];
    }
    cout << minReorder(n, connections) << endl;
    return 0;
}