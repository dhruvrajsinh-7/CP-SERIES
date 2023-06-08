#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
void dfs(vector<vector<int>> &m, int n, int i, int j, vector<vector<int>> &vis, string s)
{
    if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] == 1 || m[i][j] == 0)
    {
        return;
    }
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(s);
        return;
    }
    vis[i][j] = 1;
    dfs(m, n, i + 1, j, vis, s + "D");
    dfs(m, n, i - 1, j, vis, s + "L");
    dfs(m, n, i, j + 1, vis, s + "R");
    dfs(m, n, i - 1, j, vis, s + "U");
    vis[i][j] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    if (m[0][0] == 0)
        return {};
    if (m[n - 1][n - 1] == 0)
        return {};
    vector<vector<int>> vis(n, vector<int>(n, 0));
    string s = "";
    dfs(m, n, 0, 0, vis, s);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    vector<string> ans = findPath(m, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}