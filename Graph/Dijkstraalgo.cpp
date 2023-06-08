#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<int> ans;
    vector<int> dis(V, INT_MAX);
    queue<pair<int, int>> q;
    q.push({S, 0});
    dis[S] = 0;
    while (!q.empty())
    {
        auto curr = q.front().first;
        auto weight = q.front().second;
        q.pop();
        for (auto it : adj[curr])
        {
            int v = it[0];
            int w = it[1];
            if (w + weight < dis[v])
            {
                q.push({v, w + weight});
                dis[v] = w + weight;
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        ans.push_back(dis[i]);
    }
    return ans;
}
int main()
{
    int V = 4;
    vector<vector<int>> adj[V];
    adj[0].push_back({1, 1});
    adj[1].push_back({2, 2});
    adj[2].push_back({0, 3});
    adj[2].push_back({3, 4});
    vector<int> res = dijkstra(V, adj, 0);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}