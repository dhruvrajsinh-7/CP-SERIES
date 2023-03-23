#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
int findp(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = findp(parent[x]);
}
void unionn(int u, int v, vector<int> rank)
{
    u = findp(u);
    v = findp(v);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[v]++;
    }
}
int makeConnected(int n, vector<vector<int>> &connections, vector<int> rank)
{
    if (connections.size() < n - 1)
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        parent.push_back(i);
        rank.push_back(0);
    }
    for (auto it : connections)
    {
        unionn(it[0], it[1], rank);
    }
    int diffcomp = 0;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == i)
        {
            diffcomp++;
        }
    }
    return diffcomp - 1;
}
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> connections;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        connections.push_back({u, v});
    }
    vector<int> rank;
    cout << makeConnected(n, connections, rank);
    return 0;
}
