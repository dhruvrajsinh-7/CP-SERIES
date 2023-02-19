#include <bits/stdc++.h>
using namespace std;
int n, m;
int dfs(vector<vector<int>> mat, int i, int j, vector<vector<bool>> vis)
{
    if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] == 0 || vis[i][j] == true)
    {
        return 0;
    }
    vis[i][j] = true;
    int c = 1;
    c += dfs(mat, i + 1, j, vis);
    c += dfs(mat, i - 1, j, vis);
    c += dfs(mat, i, j + 1, vis);
    c += dfs(mat, i, j - 1, vis);
    return c;
}
int function(vector<vector<int>> matrix)
{
    int max = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1 && vis[i][j] == false)
            {
                int c = dfs(matrix, i, j, vis);
                if (c > max)
                {
                    max = c;
                }
            }
        }
    }
    return max;
}