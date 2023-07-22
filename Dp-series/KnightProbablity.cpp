#include <bits/stdc++.h>
using namespace std;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
double prob = 0.0;
double steps(int n, int k, int i, int j, vector<vector<vector<double>>> &dp)
{
    if (k == 0)
    {
        return 1.0;
    }
    if (dp[i][j][k] >= 0)
    {
        return dp[i][j][k];
    }
    if (i >= n || j >= n || i < 0 || j < 0)
    {
        return 0.0;
    }
    double prob = 0.0;
    for (int l = 0; l < 8; ++l)
    {
        int nx = i + dx[l];
        int ny = j + dy[l];
        if (nx >= 0 && ny >= 0 && nx < n && ny < n)
        {
            prob += steps(n, k - 1, nx, ny, dp) / 8.0;
        }
    }
    dp[i][j][k] = prob;
    return prob;
}
double knightProbability(int n, int k, int row, int column)
{
    vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));
    double ans = steps(n, k, row, column, dp);
    return ans;
}
int main()
{
    int n = 3, k = 2, row = 0, column = 0;
    cout << knightProbability(n, k, row, column);
    return 0;
}