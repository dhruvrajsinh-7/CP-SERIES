#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int helper(int length, vector<int> &dp, int one, int zero, int low, int high)
{
    if (length > high)
    {
        return 0;
    }
    if (dp[length] != -1)
    {
        return dp[length];
    }
    dp[length] = (length >= low) ? 1 : 0;
    dp[length] = (dp[length] + helper(length + zero, dp, one, zero, low, high)) % mod;
    dp[length] = (dp[length] + helper(length + one, dp, one, zero, low, high)) % mod;
    return dp[length];
}

int countGoodStrings(int low, int high, int zero, int one)
{
    vector<int> dp(high + 1, -1);
    return helper(0, dp, one, zero, low, high);
}
int main()
{
    cout << countGoodStrings(2, 3, 1, 1);
    return 0;
}