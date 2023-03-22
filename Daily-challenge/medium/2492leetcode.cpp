#include <bits/stdc++.h>
using namespace std;
int minScore(int n, vector<vector<int>> &roads)
{
    unordered_map<int, vector<pair<int, int>>> adj;
    int ans = INT_MAX;
    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    vector<int> vis(n + 1);
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            ans = min(ans, it.second);
            if (vis[it.first] != 1)
            {
                vis[it.first] = 1;
                q.push(it.first);
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> roads;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        roads.push_back({a, b, c});
    }
    cout << minScore(n, roads);
    return 0;
}