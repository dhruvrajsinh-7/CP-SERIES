#include <bits/stdc++.h>
using namespace std;
int solve(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;

    if (dp[n])
        return dp[n];

    int ans1 = solve(n - x, x, y, z, dp);
    int ans2 = solve(n - y, x, y, z, dp);
    int ans3 = solve(n - z, x, y, z, dp);
    dp[n] = 1 + max(max(ans1, ans2), ans3);
    return dp[n] = (dp[n] == 0) ? -1 : dp[n];
}
// Function to find the maximum number of cuts.
int maximizeTheCuts(int n, int x, int y, int z)
{
    // Your code here
    vector<int> dp(n + 1, 0);
    int ans = solve(n, x, y, z, dp);
    return ans == -1 ? 0 : ans;
}
int main()
{
    int n = 4, x = 2, y = 1, z = 1;
    cout << maximizeTheCuts(n, x, y, z);
    return 0;
}