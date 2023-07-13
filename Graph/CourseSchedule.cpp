#include <bits/stdc++.h>
using namespace std;
bool iscycle(vector<int> adj[], vector<int> &vis, int id)
{
    if (vis[id] == 0)
        return true;
    if (vis[id] == -1)
    {
        vis[id] = 0;
        for (auto edge : adj[id])
        {
            if (iscycle(adj, vis, edge))
                return true;
        }
    }
    vis[id] = 1;
    return false;
}
bool canFinish(int n, vector<vector<int>> &pre)
{
    vector<int> adj[n];
    for (auto edge : pre)
        adj[edge[1]].push_back(edge[0]);
    vector<int> vis(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (iscycle(adj, vis, i))
            return false;
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> pre(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> pre[i][0] >> pre[i][1];
    }
    cout << canFinish(n, pre) << endl;
    return 0;
}