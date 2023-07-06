#include <bits/stdc++.h>
using namespace std;
int uniquePathsIII(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int si = 0, sj = 0, count = 0, steps = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] != -1)
            {
                count++;
            }
        }
    }
    return helperdfs(grid, si, sj, count, m, n, steps);
}
int helperdfs(vector<vector<int>> &grid, int i, int j, int count, int m, int n, int steps)
{
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1)
    {
        return 0;
    }
    if (grid[i][j] == 2)
    {
        if (steps == count)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    grid[i][j] = -1;
    int ans = helperdfs(grid, i + 1, j, count, m, n, steps + 1) + helperdfs(grid, i - 1, j, count, m, n, steps + 1) + helperdfs(grid, i, j + 1, count, m, n, steps + 1) + helperdfs(grid, i, j - 1, count, m, n, steps + 1);
    grid[i][j] = 0;
    return ans;
}
