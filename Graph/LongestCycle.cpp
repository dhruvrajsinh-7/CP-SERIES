#include <bits/stdc++.h>
using namespace std;
int ans = -1;
int longestCycle(vector<int> &edges)
{
    vector<int> dnode(edges.size(), 0);
    vector<bool> vis(edges.size(), false);
    vector<bool> helper(edges.size(), false);
    for (int i = 0; i < edges.size(); i++)
    {
        if (!vis[i])
        {
            dfs(i, dnode, vis, edges, helper, 0);
        }
    }
    return ans;
}
void dfs(int node, vector<int> &dnode, vector<bool> &vis, vector<int> &edges, vector<bool> &helper, int distance)
{
    if (node != -1)
    {
        if (!vis[node])
        {
            vis[node] = true;
            dnode[node] = distance;
            helper[node] = true;
            dfs(edges[node], dnode, vis, edges, helper, distance + 1);
        }
        else if (helper[node])
        {
            ans = max(ans, distance - dnode[node]);
        }
        helper[node] = false;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> edges(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> edges[i];
    }
    cout << longestCycle(edges);
    return 0;
}
