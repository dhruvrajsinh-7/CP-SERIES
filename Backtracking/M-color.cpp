#include <bits/stdc++.h>
using namespace std;
bool isvalid(int node, int color[], int n, bool graph[101][101], int col)
{
    for (int i = 0; i < n; i++)
    {
        if (node != i && graph[i][node] == 1 && color[i] == col)
        {
            return false;
        }
    }
    return true;
}

bool helpersolve(int node, int color[], int m, int n, bool graph[101][101])
{
    if (node == n)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isvalid(node, color, n, graph, i))
        {
            color[node] = i;
            if (helpersolve(node + 1, color, m, n, graph))
            {
                return true;
            }
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    int color[n] = {0};
    if (helpersolve(0, color, m, n, graph))
        return true;
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        bool graph[101][101];
        memset(graph, 0, sizeof(graph));
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u - 1][v - 1] = 1;
            graph[v - 1][u - 1] = 1;
        }
        if (graphColoring(graph, m, n))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
}