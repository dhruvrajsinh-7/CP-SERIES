#include <bits/stdc++.h>
using namespace std;
int helper(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid)
{
    if (i == 0 && j == 0)
    {
        return grid[i][j];
    }
    if (i < 0 || j < 0)
    {
        return 1000000000;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int upper = grid[i][j] + helper(i - 1, j, dp, grid);
    int left = grid[i][j] + helper(i, j - 1, dp, grid);
    return dp[i][j] = min(left, upper);
}
int minPathSum(vector<vector<int>> &grid)
{
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    return helper(grid.size() - 1, grid[0].size() - 1, dp, grid);
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << minPathSum(grid);
    return 0;
}