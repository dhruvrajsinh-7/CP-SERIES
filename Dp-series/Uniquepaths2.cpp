#include <bits/stdc++.h>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>> &Grid)
{
    int m = Grid.size();
    int n = Grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return helper(m - 1, n - 1, dp, Grid);
}
int helper(int m, int n, vector<vector<int>> &dp, vector<vector<int>> &Grid)
{
    if (m == 0 && n == 0)
    {
        if (Grid[m][n] == 1)
        {
            return 0;
        }
        return 1;
    }
    if (m < 0 || n < 0 || Grid[m][n] == 1)
    {
        return 0;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    int up = helper(m - 1, n, dp, Grid);
    int left = helper(m, n - 1, dp, Grid);
    return dp[m][n] = up + left;
}
int main()
{
    vector<vector<int>> Grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << uniquePathsWithObstacles(Grid);
    return 0;
}