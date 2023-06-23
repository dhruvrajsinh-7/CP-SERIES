#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int ncr(int n, int r, vector<vector<int>> &dp)
{
    if (r > n)
        return 0;

    if (n == r || r == 0)
        return 1;

    if (r == 1)
        return n;

    if (dp[n][r] != -1)
        return dp[n][r];

    dp[n][r] = (ncr(n - 1, r, dp) % mod + ncr(n - 1, r - 1, dp) % mod) % mod;
    return dp[n][r];
}
int nCr(int n, int r)
{
    // code here
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));
    return ncr(n, r, dp);
}
int main()
{
    int n = 3;
    int r = 2;
    cout << nCr(n, r);
    return 0;
}