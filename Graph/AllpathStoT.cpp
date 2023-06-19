#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> paths;

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<int> path;
    dfs(0, graph, path);
    return paths;
}

void dfs(int node, vector<vector<int>> &graph, vector<int> &path)
{
    path.push_back(node);

    if (node == graph.size() - 1)
    {
        paths.push_back(path);
    }
    else
    {
        for (int neighbor : graph[node])
        {
            dfs(neighbor, graph, path);
        }
    }
    path.pop_back();
}
int main()
{
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> ans = allPathsSourceTarget(graph);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}