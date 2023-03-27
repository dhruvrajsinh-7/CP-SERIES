#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else
            {
                vis[i][j] = 0;
            }
            if (grid[i][j] == 1)
            {
                count++;
            }
        }
    }
    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};
    int cnt = 0, t1 = 0;
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        t1 = max(t1, t);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newR = r + row[i];
            int newC = c + col[i];
            if (newR >= 0 && newC >= 0 && newR < n && newC < m && vis[newR][newC] == 0 && grid[newR][newC] == 1)
            {
                vis[newR][newC] = 2;
                q.push({{newR, newC}, t + 1});
                cnt++;
            }
        }
    }
    if (cnt != count)
    {
        return -1;
    }
    return t1;
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
    cout << orangesRotting(grid);
    return 0;
}