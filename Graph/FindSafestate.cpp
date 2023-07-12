#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &graph, vector<int> &color, int node)
{
    color[node] = 1;

    for (auto cur : graph[node])
        if ((color[cur] == 0 && dfs(graph, color, cur)) || color[cur] == 1)
            return true;

    color[node] = 2;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    vector<int> color(graph.size()), result;

    for (int i = 0; i < graph.size(); i++)
        if (color[i] == 2 || !dfs(graph, color, i))
            result.push_back(i);

    return result;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        graph[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    vector<int> ans = eventualSafeNodes(graph);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}