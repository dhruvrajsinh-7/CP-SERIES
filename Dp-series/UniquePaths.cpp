#include <bits/stdc++.h>
using namespace std;
int helper(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
    {
        return 1;
    }
    if (m < 0 || n < 0)
    {
        return 0;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    int up = helper(m - 1, n, dp);
    int left = helper(m, n - 1, dp);
    return dp[m][n] = up + left;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return helper(m - 1, n - 1, dp);
}
int main()
{
    int m = 3, n = 7;
    cout << uniquePaths(m, n);
    return 0;
}