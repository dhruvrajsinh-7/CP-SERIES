int m, n;
int mod = 1e9 + 7;

int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int parent)
{
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= parent)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    dp[i][j] = ((helper(i + 1, j, grid, dp, grid[i][j]) % mod) +
                (helper(i - 1, j, grid, dp, grid[i][j]) % mod) +
                (helper(i, j + 1, grid, dp, grid[i][j]) % mod) +
                (helper(i, j - 1, grid, dp, grid[i][j]) % mod) + 1) %
               mod;

    return dp[i][j];
}

int countPaths(vector<vector<int>> &grid)
{
    m = grid.size();
    n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == -1)
            {
                helper(i, j, grid, dp, -1);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = (ans + dp[i][j]) % mod;
        }
    }
    return ans;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << countPaths(grid);
    return 0;
}