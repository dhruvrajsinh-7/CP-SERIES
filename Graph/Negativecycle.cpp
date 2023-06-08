#include <bits/stdc++.h>
using namespace std;
int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{
    // Code here
    vector<int> dist(n, 1000000007);
    dist[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                flag = 1;
            }
        }
        if (i == n - 1 && flag == 1)
            return 1;
    }
    return 0;
}
int main()
{
    int n = 3;
    vector<vector<int>> edges = {{0, 1, -1}, {1, 2, -2}, {2, 0, -3}};
    cout << isNegativeWeightCycle(n, edges);
}