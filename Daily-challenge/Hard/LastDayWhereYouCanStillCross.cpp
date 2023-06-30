#include <bits/stdc++.h>
using namespace std;
bool helper(int i, int j, vector<vector<int>> &res, vector<vector<bool>> &visited, int n, int m)
{
    if (i <= 0 || j <= 0 || i > n || j > m || res[i][j] || visited[i][j])
    {
        return false;
    }
    if (i == n)
    {
        return true;
    }
    visited[i][j] = true;
    return helper(i + 1, j, res, visited, n, m) ||
           helper(i, j + 1, res, visited, n, m) ||
           helper(i - 1, j, res, visited, n, m) ||
           helper(i, j - 1, res, visited, n, m);
}
int latestDayToCross(int n, int m, vector<vector<int>> &cells)
{
    vector<vector<int>> res(n + 1, vector<int>(m + 1, 0));
    int start = 1, end = cells.size(), ans = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        for (int i = 0; i < mid; i++)
        {
            res[cells[i][0]][cells[i][1]] = 1;
        }
        bool flag = false;
        vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            flag = flag | helper(1, i, res, visited, n, m);
        }
        if (flag)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        for (int i = 0; i < mid; i++)
        {
            res[cells[i][0]][cells[i][1]] = 0;
        }
    }
    return ans;
}
int main()
{
    int n = 3, m = 3;
    vector<vector<int>> cells = {{1, 2}, {2, 1}, {3, 3}, {2, 2}, {1, 1}, {1, 3}, {2, 3}, {3, 2}, {3, 1}};
    cout << latestDayToCross(n, m, cells);
    return 0;
}