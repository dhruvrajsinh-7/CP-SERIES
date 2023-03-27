#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> dis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({{i, j}, 0});
                vis[i][j] = true;
            }
            else
            {
                vis[i][j] = false;
            }
        }
    }
    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int step = q.front().second;
        q.pop();
        dis[r][c] = step;
        for (int i = 0; i < 4; i++)
        {
            int newR = r + row[i];
            int newC = c + col[i];
            if (newR >= 0 && newC >= 0 && newR < n && newC < m && vis[newR][newC] == false)
            {
                vis[newR][newC] = true;
                q.push({{newR, newC}, step + 1});
            }
        }
    }
    return dis;
}
int main()
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
    vector<vector<int>> ans = nearest(grid);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}