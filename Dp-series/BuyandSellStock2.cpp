#include <bits/stdc++.h>
using namespace std;
int helper(int idx, int buy, vector<int> &price, vector<vector<int>> &dp, int n)
{
    if (idx >= n)
    {
        return 0;
    }
    int profit = 0;
    if (dp[idx][buy] != -1)
    {
        return dp[idx][buy];
    }
    if (buy == 0)
    {
        dp[idx][buy] = max(-price[idx] + helper(idx + 1, 1, price, dp, n), helper(idx + 1, 0, price, dp, n));
    }
    else
    {
        dp[idx][buy] = max(price[idx] + helper(idx + 1, 0, price, dp, n), helper(idx + 1, 1, price, dp, n));
    }
    profit = dp[idx][buy];
    return profit;
}
int maxProfit(vector<int> &price)
{
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return helper(0, 0, price, dp, n);
}
int main()
{
    vector<int> price = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(price);
    return 0;
}