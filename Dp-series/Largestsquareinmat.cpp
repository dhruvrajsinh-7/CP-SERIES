#include <bits/stdc++.h>
using namespace std;
int maxx = 0;
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    // code here
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    helper(0, 0, mat, dp, n, m);
    return maxx;
}
int helper(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp, int n, int m)
{
    if (i >= n || j >= m)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int right = helper(i, j + 1, mat, dp, n, m);
    int down = helper(i + 1, j, mat, dp, n, m);
    int diagonal = helper(i + 1, j + 1, mat, dp, n, m);

    if (mat[i][j] == 1)
    {
        dp[i][j] = 1 + min(right, min(down, diagonal));
        maxx = max(maxx, dp[i][j]);
        return dp[i][j];
    }
    else
    {
        return dp[i][j] = 0;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << maxSquare(n, m, mat) << endl;
    return 0;
}