#include <bits/stdc++.h>
using namespace std;
int helper(int i, int j, int n, int m, vector<vector<int>> &M, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int downrightD = helper(i + 1, j + 1, n, m, M, dp);
    int right = helper(i, j + 1, n, m, M, dp);
    int uprightD = helper(i - 1, j + 1, n, m, M, dp);
    return dp[i][j] = M[i][j] + max(max(downrightD, right), uprightD);
}
int maxGold(int n, int m, vector<vector<int>> M)
{
    // code here
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int res = helper(i, 0, n, m, M, dp);
        ans = max(ans, res);
    }
    return ans;
}
int main()
{
    vector<vector<int>> v = {{1, 3, 3},
                             {2, 1, 4},
                             {0, 6, 4}};
    cout << maxGold(3, 3, v);
    return 0;
}