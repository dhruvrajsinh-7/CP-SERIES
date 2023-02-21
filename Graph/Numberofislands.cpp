#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &vis)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] == true || grid[i][j] == '0')
    {
        return;
    }
    vis[i][j] = true;
    dfs(grid, i + 1, j, vis);
    dfs(grid, i, j + 1, vis);
    dfs(grid, i - 1, j, vis);
    dfs(grid, i, j - 1, vis);
    dfs(grid, i + 1, j + 1, vis);
    dfs(grid, i + 1, j - 1, vis);
    dfs(grid, i - 1, j + 1, vis);
    dfs(grid, i - 1, j - 1, vis);
}
int numIslands(vector<vector<char>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && vis[i][j] == false)
            {
                dfs(grid, i, j, vis);
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid;
    for (int i = 0; i < n; i++)
    {
        vector<char> row;
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            row.push_back(x);
        }
        grid.push_back(row);
    }
    cout << numIslands(grid);
    return 0;
}