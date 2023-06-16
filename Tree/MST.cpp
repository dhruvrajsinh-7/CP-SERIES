#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    vector<bool> visit(V, false);
    int ans = 0;
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int x = p.second;
        int w = p.first;
        if (visit[x])
            continue;
        visit[x] = true;
        ans += w;
        for (auto y : adj[x])
        {
            if (!visit[y[0]])
            {
                pq.push({y[1], y[0]});
            }
        }
    }
    return ans;
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << spanningTree(V, adj);
    return 0;
}