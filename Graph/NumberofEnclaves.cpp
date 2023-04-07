#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] == 1 || grid[i][j] == 0)
    {
        return;
    }
    vis[i][j] = 1;
    dfs(i + 1, j, vis, grid);
    dfs(i, j + 1, vis, grid);
    dfs(i - 1, j, vis, grid);
    dfs(i, j - 1, vis, grid);
}
int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((j == 0 || i == 0 || i == n - 1 || j == m - 1) && vis[i][j] == 0)
            {
                dfs(i, j, vis, grid);
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                count++;
            }
        }
    }
    return count;
}
int maim()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << numEnclaves(grid);
    return 0;
}